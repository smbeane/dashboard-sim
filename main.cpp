#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <simulator.hpp>
#include <color/colors.hpp>
#include <components/components.hpp>
#include <pages/pages.hpp>
#include <utils/inputs/rotary_encoder.hpp>

// TODO: split into lib and src

const int pixel_gap  { 2 };
const int pixel_size { 18 };
std::array<Color, MATRIX_SIZE> grid;

bool handle_action(Page* page, SDL_Event event) {
    bool quit = false;
    
    switch (event.key.key) {
        case SDLK_ESCAPE:
            quit = true;
            break;
        case SDLK_A:
            page->execute_action(RotaryAction::Left, 0);
            break;
        case SDLK_LEFT:
            page->execute_action(RotaryAction::Left, 1);
            break;
        case SDLK_D:
            page->execute_action(RotaryAction::Right, 0);
            break;
        case SDLK_RIGHT:   
            page->execute_action(RotaryAction::Right, 1);
            break;
        case SDLK_S:
            page->execute_action(RotaryAction::Press, 0);
            break;
        case SDLK_DOWN:
            page->execute_action(RotaryAction::Press, 1);
            break;
    }

    return quit;
}

int main ( int argc, char* argv[] ) {
    
    std::vector<int> inputs = parse_args(argc, argv);
    int page_idx = inputs[0];
    int window_width = inputs[3]; 
    int window_height = inputs[4];


    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    std::vector<std::unique_ptr<Page>> pages;
    pages.push_back(std::make_unique<ComponentPage>("Component Renderer"));
    pages.push_back(std::make_unique<TimePage>("Time Renderer")); 
    pages.push_back(std::make_unique<ColorPickerPage>());

    if (page_idx < 0 || page_idx >= static_cast<int>(pages.size())) {
        std::cerr << "Warning: invalid page index " << page_idx << ", defaulting to page 0\n";
        page_idx = 0;
    }

    Page* selected_page = pages.at(page_idx).get();

    bool quit = false;
    SDL_Event event;
    
    while ( quit == false ) {

        while ( SDL_PollEvent( &event ) == true ) {
            if ( event.type == SDL_EVENT_QUIT ) {
                quit = true;
            }  

            else if (event.type == SDL_EVENT_KEY_DOWN) {
                quit = handle_action(selected_page, event);
            }
        }
        
        selected_page->render_page(grid);
        render.render_matrix(grid);
        selected_page->update_data();
    }

    return 0;
}