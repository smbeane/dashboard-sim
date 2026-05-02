#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <SDL3/SDL_pixels.h>

class Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        bool visible;

        Color() : r ( 0 ), g ( 0 ), b ( 0 ), visible( 0 )  {}

        Color(uint8_t setR, uint8_t setG, uint8_t setB, bool v) 
            : r ( setR ), g ( setG ), b ( setB ), visible ( v ) {
        }   

        SDL_Color getSDL_Color ();
        bool is_visible() { return visible; }
};




#endif // COLOR_HPP