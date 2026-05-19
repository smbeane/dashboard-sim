#include "color.hpp"

SDL_Color Color::getSDL_Color() {
    SDL_Color new_color;
    new_color.r = r;
    new_color.g = g;
    new_color.b = b;
    new_color.a = 255;

    return new_color;
}

std::ostream& operator<<(std::ostream& os, const Color& color) {
    os << "(" << std::to_string(color.r) << ", " << std::to_string(color.g) << ", " <<  std::to_string(color.b) << ")" << std::endl;

    return os;
}