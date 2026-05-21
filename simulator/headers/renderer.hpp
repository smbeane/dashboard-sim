#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL3/SDL.h>

#include <string>
#include <array>
#include <color/color/color.hpp>
#include <components/component.hpp>


class Renderer {
    public:
        int window_width;
        int window_height;
        int pixel_width;
        int pixel_height;
        int pixel_gap;
        std::string window_name; 

        
        /**
         * @brief Default constructor initializes renderer state and creates the window.
         */
        Renderer() : window_width{ 0 }, window_height { 0 }, 
        pixel_width{ 0 }, pixel_height{ 0 }, pixel_gap{ 0 },
        window_name{"Renderer"}, window{nullptr}, 
        renderer {nullptr} {
            init_window();
        }
        
        /**
         * @brief Constructs a renderer and initializes the SDL window.
         *
         * @param wwidth  Pixel width of the window.
         * @param wheight Pixel height of the window.
         * @param pwidth  Width of each rendered matrix pixel.
         * @param pheight Height of each rendered matrix pixel.
         * @param pgap    Gap between rendered matrix pixels.
         * @param name    The window title.
         */
        Renderer(int wwidth, int wheight, int pwidth, int pheight, int pgap, std::string name = "Renderer") :
        window_width{ wwidth }, window_height{ wheight }, pixel_width{ pwidth },
        pixel_height{ pheight }, pixel_gap{ pgap }, window_name{ name }, 
        window{nullptr}, renderer {nullptr} {
            sdl_init_success = init_window();
        }
        
        /**
         * @brief Returns whether the renderer successfully initialized.
         *
         * @return true if the SDL window and renderer are ready.
         */
        bool able_to_render();

        /**
         * @brief Draws the provided matrix buffer to the SDL window.
         *
         * @param grid The pixel buffer to render.
         * @return true when rendering completed successfully.
         */
        bool render_matrix(std::array<Color, MATRIX_SIZE> grid);
        
        /**
         * @brief Destroys the window and shuts down SDL.
         */
        void close_window();

        private: 
        SDL_Window* window;
        SDL_Renderer* renderer;
        bool sdl_init_success;
        
        bool init_window();
        
    };

#endif // RENDERER_HPP