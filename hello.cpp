#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>

#include <color.hpp>
#include <renderer.hpp>
#include <vector>

const int width      { 64 * 20 };
const int height     { 32 * 20 };
const int pixel_gap  { 2 };
const int pixel_size { 18 };

std::vector<Color> grid (64 * 32);

int main ( int argc, char* args[] ) {
    int exitCode{ 0 };

    Renderer render( width, height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    if ( !(render.able_to_render())) {
        
        SDL_Log ( "Window could not initialize \n");   
        return 1;

    }
    
    bool quit{ false };
    int curr_color = 0;
    bool increase = true;

    SDL_Event e;
    SDL_zero( e );
    
    while ( quit == false ) {
        while ( SDL_PollEvent( &e ) == true ) {
            if ( e.type == SDL_EVENT_QUIT ) {
                quit = true;
            }

        }
        
        std::fill(grid.begin(), grid.end(), Color(curr_color, curr_color, curr_color));

        curr_color = increase ? curr_color + 1 : curr_color - 1;
        if (increase && curr_color >= 255) increase = false;
        else if (~increase && curr_color <= 0) increase = true;

        SDL_Delay(10);
    }

    return exitCode;
}