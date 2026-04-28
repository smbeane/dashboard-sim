#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL3/SDL.h>

#include <string>
#include <array>
#include <color.hpp>

class Renderer {
    public:
        int window_width;
        int window_height;
        int pixel_width;
        int pixel_height;
        int pixel_gap;
        std::string window_name; 

        
        /**
         * @brief no instantiations, all variables set to 0 and inits window
         */
        Renderer() : window_width{ 0 }, window_height { 0 }, 
        pixel_width{ 0 }, pixel_height{ 0 }, pixel_gap{ 0 },
        window_name{"Renderer"}, window{nullptr}, 
        renderer {nullptr} {
            init_window();
        }
        
        /**
         * @brief sets all variables, inits window and renderer
         * 
         * @param wwidth  pixel width of the window
         * 
         * @param wheight pixel height of the window
         * 
         * @param pwidth  pixel width of each "pixel" begin rendered
         * 
         * @param pheight pixel height of each "pixel" being rendered
         * 
         * @param pgap    pixel gap between "pixels" being rendered
         * 
         * @param name    the name of the rendering window
         */
        Renderer(int wwidth, int wheight, int pwidth, int pheight, int pgap, std::string name = "Renderer") :
        window_width{ wwidth }, window_height{ wheight }, pixel_width{ pwidth },
        pixel_height{ pheight }, pixel_gap{ pgap }, window_name{ name }, 
        window{nullptr}, renderer {nullptr} {
            sdl_init_success = init_window();
        }
        
        bool able_to_render();

        bool render_matrix(std::array<Color, 64*32> grid);
        
        void close_window();
        
        void render_loop();
        
        private: 
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool sdl_init_success;
        
        bool init_window();
        

    };
 



#endif // RENDERER_HPP