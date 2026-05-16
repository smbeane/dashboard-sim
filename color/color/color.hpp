#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <SDL3/SDL_pixels.h>

class Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        bool is_visible;

        Color() : r ( 0 ), g ( 0 ), b ( 0 ), is_visible( 0 )  {}


        /**
         * @brief Constructs a color of defined RGB 
         * 
         * @param r 8-b red value of Color (0-255)
         * @param g 8-bit green value of Color (0-255)
         * @param b 8-bit blue value of Color (0-255)
         */
        Color(uint8_t r, uint8_t g, uint8_t b) : r ( r ), g ( g ), b ( b ), is_visible( 1 )  {}

        /**
         * @brief Constructs a Color of defined RGB and transparency
         * 
         * @param r 8-b red value of Color (0-255)
         * @param g 8-bit green value of Color (0-255)
         * @param b 8-bit blue value of Color (0-255)
         * @param v Sets visibility of color (0 for transparent, 1 for visible)
         */
        Color(uint8_t r, uint8_t g, int8_t b, bool v) 
            : r ( r ), g ( g ), b ( b ), is_visible ( v ) {
        }   

        /**
         * @brief Gets the corresponding SDL_Color
         * 
         * @return SDL_Color corresponding to the color
         */
        SDL_Color getSDL_Color ();

        /**
         * @brief Checks if color is visible
         * 
         * @returns bool if visible
         */
        bool is_transparent() { return is_visible; }
};




#endif // COLOR_HPP