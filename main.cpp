#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <colors.hpp>
#include <simulator.hpp>
#include <components/components.hpp>
#include <pages/pages.hpp>

const int pixel_gap  { 2 };
const int pixel_size { 18 };

std::array<Color, 64*32> grid;

int main ( int argc, char* argv[] ) {
    
    std::vector<int> inputs = parse_args(argc, argv);
    int page_idx = inputs[0];
    int window_width = inputs[3]; 
    int window_height = inputs[4];
    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    std::vector<std::unique_ptr<Page>> pages;
    pages.push_back(std::make_unique<ComponentPage>("Component Renderer"));
    pages.push_back(std::make_unique<TimePage>("Time Renderer")); 

    Page* selected_page = pages.at(page_idx).get();

    bool quit = false;
    SDL_Event e;
    SDL_zero ( e );
    
    while ( quit == false ) {
        while ( SDL_PollEvent( &e ) == true ) {
            if ( e.type == SDL_EVENT_QUIT ) {
                quit = true;
            }  
        }
        
        selected_page->render_page(grid);
        render.render_matrix(grid);

        SDL_Delay(1000);

        selected_page->update_data();
    }

    return 0;
}