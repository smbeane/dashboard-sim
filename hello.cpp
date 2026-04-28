#include <string>
#include <array>
#include <vector>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <color.hpp>
#include <renderer.hpp>
#include <fonts.hpp>
#include <line.hpp>
#include "components/rectangle/rectangle.hpp"

const int pixel_gap  { 2 };
const int pixel_size { 18 };
std::array<Color, 64*32> grid;


std::vector<std::string> flags = {"--page", "--font_size", "--refresh_rate", "--window_width", "--window_height"};

std::vector<int> parse_args (int argc, char* args[]) {
    std::vector<int> inputs(5, 0);
    inputs[3] = 1408;
    inputs[4] = 704;
    
    for (int i = 0; i < argc; i++) {
        std::string flag(args[i]);
        
        if (!(i + 1 < argc)) continue; 
        std::string value(args[i + 1]);
        for (int j = 0; j < flags.size(); j++) {
            if ( flag == flags[j] ) inputs[j] = std::stoi(value);
        } 
    }

    std::cout << "Page Selection: " << inputs[0] << std::endl;
    std::cout << "Font Height: " << inputs[1] << std::endl;
    std::cout << "FPS: " << inputs[2] << std::endl;
    std::cout << "Window width: " << inputs[3] << std::endl;
    std::cout << "Window height: " << inputs[4] << std::endl;

    return inputs;

}

int main ( int argc, char* argv[] ) {
    int exitCode{ 0 };

    std::vector<int> inputs = parse_args(argc, argv);
    int window_width = inputs[3]; 
    int window_height = inputs[4];

    Renderer render( window_width, window_height, pixel_size, pixel_size, pixel_gap, std::string("LED Matrix Simulator"));

    if ( !(render.able_to_render())) {
        
        SDL_Log ( "Window could not initialize \n");   
        return 1;

    }

    std::string line1 = "abcdefghijklmnop";
    std::string line2 = "qrstuvwxyz";
    std::string line3 = "0123456789";
    int x_start = 0;

//     for (int c = 0; c < line1.length(); c++) {
//         uint16_t character1 = font_3x5[line1[c] - 'a'];
//         uint16_t character2, character3;

//         if (c < 10) {
//             character2 = font_3x5[line2[c] - 'a'];
//             character3 = font_3x5[line3[c] - 'a'];
//         } else {
//             character2 = 0b000000000000000;
//             character3 = 0b000000000000000;
//         }

//         uint16_t mask = 0x4000; 

//         for (int j = 0; j < 5; j++) {         
//             for (int i = 0; i < 3; i++) {     
                
//                 int target_index1 = (j * 64) + (x_start + i);
//                 int target_index2 = ((j + 6) * 64) + (x_start + i);
//                 int target_index3 = ((j + 12) * 64) + (x_start + i);

//                 if (character1 & mask) {
//                     grid[target_index1] = Color(255, 255, 255);
//                 } else {
//                     grid[target_index1] = Color(0, 0, 0);       
//                 }

//                 if (character2 & mask) {
//                     grid[target_index2] = Color(255, 255, 255);
//                 } else {
//                     grid[target_index2] = Color(0, 0, 0);       
//                 }

//                 mask >>= 1; 
//             }
//         }

//     x_start += 4; 
//     }

    Rectangle rect(1, 1, 10, 10, Color(100, 100, 100), Color(255, 153, 123));
    rect.render_component(grid);

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



        // grid.fill(Color(curr_color, curr_color, curr_color));

        // curr_color = increase ? curr_color + 1 : curr_color - 1;
        // if (increase && curr_color >= 255) increase = false;
        // else if (~increase && curr_color <= 0) increase = true;

        SDL_Delay(10);
    }

    return exitCode;
}