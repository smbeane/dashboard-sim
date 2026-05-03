#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <color.hpp>
#include <simulator.hpp>
#include <components.hpp>

const int pixel_gap  { 2 };
const int pixel_size { 18 };
const Color profile_color(63, 81, 181, 1);
const Color white(255, 255, 255, 1);
const Color black(0, 0, 0, 1);

std::array<Color, 64*32> grid;

int main ( int argc, char* argv[] ) {
    
    std::vector<int> inputs = parse_args(argc, argv);
    int window_width = inputs[3]; 
    int window_height = inputs[4];
    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    std::vector<std::unique_ptr<Component>> components;

    components.push_back(std::make_unique<Rectangle>(3, 3, 10, 10, white, profile_color));
    components.push_back(std::make_unique<Line>(15, 3, profile_color, 24, 12));
    components.push_back(std::make_unique<Circle>(32, 8, white, profile_color, 5));
    components.push_back(std::make_unique<Progress_bar>(40, 4, 20, 5, 50, white, profile_color));
    components.push_back(std::make_unique<Slider>(40, 12, white, profile_color, 20, 6));
    components.push_back(std::make_unique<Textbox>(5, 17, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 2, profile_color, black));
    components.push_back(std::make_unique<Textbox>(5, 24, " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 2, profile_color, black));
    
    bool quit = false;
    SDL_Event e;
    SDL_zero ( e );
    
    while ( quit == false ) {
        while ( SDL_PollEvent( &e ) == true ) {
            if ( e.type == SDL_EVENT_QUIT ) {
                quit = true;
            }  
        }

        for (auto& c : components) c->render_component(grid);
        render.render_matrix(grid);
        
        SDL_Delay(1000);

        Textbox* text = dynamic_cast<Textbox*>(components[5].get());
        Textbox* characters = dynamic_cast<Textbox*>(components[6].get());

        if (text) {
            text->scroll_text();
        } 
        if (characters) {
            characters->scroll_text();
        } 
    }

    return 0;
}