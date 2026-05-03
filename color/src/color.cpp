#include "../headers/color.hpp"


SDL_Color Color::getSDL_Color() {
    SDL_Color new_color;
    new_color.r = r;
    new_color.g = g;
    new_color.b = b;
    new_color.a = 255;

    return new_color;
}