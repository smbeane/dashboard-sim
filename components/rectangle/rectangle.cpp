#include "rectangle.hpp"

void Rectangle::render_component(std::array<Color, 64*32>& matrix) {

    if (primary.is_visible()) {
        for (int i = x; i < x + width ; i++) {
            matrix[y * 64 + i] = primary;
            matrix[(y + height - 1) * 64 + i] = primary;
        }
    }   

    for (int j = y + 1; j < (y + height - 1); j++) {
        if (primary.is_visible()) matrix[j * 64 + x] = primary;
        
        if (secondary.is_visible()) {
            for (int i = x + 1; i < (x + width - 1); i++) {
                matrix[j * 64 + i] = secondary;
            }
        }

        if (primary.is_visible()) matrix[j * 64 + x + width - 1] = primary;
    }
}