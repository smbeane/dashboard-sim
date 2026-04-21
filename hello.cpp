#include <string>
#include <vector>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <color.hpp>
#include <renderer.hpp>
#include <fonts.hpp>


const int pixel_gap  { 2 };
const int pixel_size { 18 };

const int width      { 64 * (pixel_size + pixel_gap * 2) };
const int height     { 32 * (pixel_size + pixel_gap * 2) };

std::vector<Color> grid (64 * 32);

int main ( int argc, char* args[] ) {
    int exitCode{ 0 };

    Renderer render( width, height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    if ( !(render.able_to_render())) {
        
        SDL_Log ( "Window could not initialize \n");   
        return 1;

    }

    std::string line1 = "abcdefghijklmnop";
    std::string line2 = "qrstuvwxyz";
    std::string line3 = "0123456789";
    int x_start = 0;

    for (int c = 0; c < line1.length(); c++) {
        uint16_t character1 = font_3x5[line1[c] - 'a'];
        uint16_t character2, character3;

        if (c < 10) {
            character2 = font_3x5[line2[c] - 'a'];
            character3 = font_3x5[line3[c] - 'a'];
        } else {
            character2 = 0b000000000000000;
            character3 = 0b000000000000000;
        }

        uint16_t mask = 0x4000; 

        for (int j = 0; j < 5; j++) {         
            for (int i = 0; i < 3; i++) {     
                
                int target_index1 = (j * 64) + (x_start + i);
                int target_index2 = ((j + 6) * 64) + (x_start + i);
                int target_index3 = ((j + 12) * 64) + (x_start + i);

                if (character1 & mask) {
                    grid[target_index1] = Color(255, 255, 255);
                } else {
                    grid[target_index1] = Color(0, 0, 0);       
                }

                if (character2 & mask) {
                    grid[target_index2] = Color(255, 255, 255);
                } else {
                    grid[target_index2] = Color(0, 0, 0);       
                }

                // if (character3 & mask) {
                //     grid[target_index3] = Color(255, 255, 255);
                // } else {
                //     grid[target_index3] = Color(0, 0, 0);       
                // }

                mask >>= 1; 
            }
        }

    x_start += 4; 
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
        

        render.render_matrix(grid);

        curr_color = increase ? curr_color + 1 : curr_color - 1;
        if (increase && curr_color >= 255) increase = false;
        else if (~increase && curr_color <= 0) increase = true;

        SDL_Delay(10);
    }

    return exitCode;
}