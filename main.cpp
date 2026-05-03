#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <colors.hpp>
#include <simulator.hpp>
#include <components.hpp>
#include <pages.hpp>

const int pixel_gap  { 2 };
const int pixel_size { 18 };

std::array<Color, 64*32> grid;

int main ( int argc, char* argv[] ) {
    
    std::vector<int> inputs = parse_args(argc, argv);
    int window_width = inputs[3]; 
    int window_height = inputs[4];
    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    // ComponentPage components ("Component Page");
    TimePage time_page ("Time");

    bool quit = false;
    SDL_Event e;
    SDL_zero ( e );
    
    while ( quit == false ) {
        while ( SDL_PollEvent( &e ) == true ) {
            if ( e.type == SDL_EVENT_QUIT ) {
                quit = true;
            }  
        }
        
        time_page.render_page(grid);
        render.render_matrix(grid);

        SDL_Delay(1000);

        time_page.update_data();
    }

    return 0;
}