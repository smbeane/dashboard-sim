#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
#include <SDL3/SDL_pixels.h>

class Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;

        Color() : r { 0 }, g { 0 }, b { 0 } {}

        Color(uint8_t setR, uint8_t setG, uint8_t setB) 
            : r { setR }, g { setG }, b { setB } {
        }   

        SDL_Color getSDL_Color ();
};




#endif // COLOR_HPP