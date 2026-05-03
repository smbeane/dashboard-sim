#include <string>
#include <array>
#include <vector>
#include <memory>
#include <iostream>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include <color.hpp>
#include <renderer.hpp>

#include <components.hpp>


const int pixel_gap  { 2 };
const int pixel_size { 18 };
const Color profile_color(63, 81, 181, 1);
const Color white(255, 255, 255, 1);
const Color black(0, 0, 0, 1);

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

    std::vector<std::unique_ptr<Component>> components;

    components.push_back(std::make_unique<Rectangle>(3, 3, 10, 10, white, profile_color));
    components.push_back(std::make_unique<Line>(15, 3, profile_color, 24, 12));
    components.push_back(std::make_unique<Circle>(32, 8, white, profile_color, 5));
    components.push_back(std::make_unique<Progress_bar>(40, 4, 20, 5, 50, white, profile_color));
    components.push_back(std::make_unique<Slider>(40, 12, white, profile_color, 20, 6));
    components.push_back(std::make_unique<Textbox>(5, 17, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 2, profile_color, black));
    components.push_back(std::make_unique<Textbox>(5, 24, " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 2, profile_color, black));
    for (auto& c : components) c->render_component(grid);

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

        SDL_Delay(1000);

        Textbox* text = dynamic_cast<Textbox*>(components[5].get());
        Textbox* characters = dynamic_cast<Textbox*>(components[6].get());

        if (text) {
            text->scroll_text();
        } 
        if (characters) {
            characters->scroll_text();
        } 

        for (auto& c : components) c->render_component(grid);

        

    }

    return exitCode;
}