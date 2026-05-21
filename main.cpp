#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>
#include <optional>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <simulator.hpp>
#include <color/colors.hpp>
#include <components/components.hpp>
#include <pages/pages.hpp>
#include <utils/inputs/rotary_encoder.hpp>
#include <profile/profile.hpp>

const int pixel_gap  { 2 };
const int pixel_size { 18 };

const inline std::vector<std::string> page_names = {"Component Demo", "Time Display", "Color Picker"};

template<class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

std::vector<std::function<std::unique_ptr<Page>(Profile p)>> factory { 
    [](Profile p) {
        return std::make_unique<PageSelectionPage>("Page Selection", page_names);
    },
    [](Profile p) {
        return std::make_unique<ComponentPage>("Component Demo", p);
    }, 
    [](Profile p) {
        return std::make_unique<TimePage>("Time Display", p);
    }, 
    [](Profile p) {
        return std::make_unique<ColorPickerPage>("Color Picker");
    }
}; 

std::vector<std::unique_ptr<Page>> page_stack;

std::array<Color, MATRIX_SIZE> grid;
std::vector<std::unique_ptr<Page>> pages;
int page_idx;

/**
 * @brief Converts SDL keyboard events into page actions.
 *
 * @param page The active page receiving the action.
 * @param event The SDL event to process.
 * @return true when the application should quit.
 */
PageActionResult handle_action(Page* page, SDL_Event event) {
    switch (event.key.key) {
        case SDLK_A:
            return page->execute_action(RotaryAction::Left, 0);
        case SDLK_LEFT:
            return page->execute_action(RotaryAction::Left, 1);
        case SDLK_D:
            return page->execute_action(RotaryAction::Right, 0);
        case SDLK_RIGHT:   
            return page->execute_action(RotaryAction::Right, 1);
        case SDLK_S:
            return page->execute_action(RotaryAction::Press, 0);
        case SDLK_DOWN:
            return page->execute_action(RotaryAction::Press, 1);
    }

    return {};
}

template <typename T, typename... Args>
/**
 * @brief Creates and owns a new page instance.
 *
 * @tparam T The page type.
 * @param name Page title.
 * @param args Constructor arguments forwarded to the page.
 * @return Raw pointer to the created page.
 */
Page* add_page(std::string name, Args... args) {
    std::unique_ptr<T> page = std::make_unique<T>(name, std::forward<Args>(args)...);
    T* ptr = page.get();
    pages.push_back(std::move(page));

    return ptr;
}


void check_profile() {
    
}

int main ( int argc, char* argv[] ) {
    
    std::vector<int> inputs = parse_args(argc, argv);
    page_idx = inputs[0];
    int window_width = inputs[3]; 
    int window_height = inputs[4];

    Profile p;

    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    std::vector<Page*> page_ptrs;
    
    page_stack.push_back(factory[0](p));

    bool quit = false;
    SDL_Event event;
    
    while ( quit == false ) {

        while ( SDL_PollEvent( &event ) == true ) {
            if ( event.type == SDL_EVENT_QUIT ) {
                quit = true;
            }  

            else if (event.type == SDL_EVENT_KEY_DOWN) {
                if (event.key.key == SDLK_ESCAPE) {
                    quit = true;
                    break;
                } else {
                    PageActionResult action = handle_action(page_stack.back().get(), event);
                    std::visit(overloaded {
                        [] (std::monostate) { },
                        [p] (NavigateAction const& nav) { 
                            grid.fill(BLACK);
                            page_stack.clear();
                            page_stack.push_back(factory[nav.index](p));
                         },
                        [] (ReplaceAction rep) { 
                            grid.fill(BLACK);
                            page_stack.at((page_stack.size() - 1)) = std::move(rep.page);
                         },
                        [] (PushAction push) { 
                            grid.fill(BLACK);
                            page_stack.push_back(std::move(push.page));
                        },
                        [p] (PopAction pop) { 
                            grid.fill(BLACK);
                            page_stack.pop_back(); 
                            if (page_stack.empty()) page_stack.push_back(std::make_unique<TimePage>("Time Display", p));
                        }}, std::move(action));
                }
            }
        }
        
        page_stack.back()->render_page(grid);
        render.render_matrix(grid);
        page_stack.back()->update_data();
    }

    return 0;
}