#include "rectangle.hpp"

void Rectangle::render_component(std::array<Color, 64*32>& matrix) {

    if (border_color.is_visible()) {
        for (int i = x; i < x + width ; i++) {
            matrix[y * 64 + i] = border_color;
            matrix[(y + height - 1) * 64 + i] = border_color;
        }
    }   

    for (int j = y + 1; j < (y + height - 1); j++) {
        if (border_color.is_visible()) matrix[j * 64 + x] = border_color;
        
        if (infill_color.is_visible()) {
            for (int i = x + 1; i < (x + width - 1); i++) {
                matrix[j * 64 + i] = infill_color;
            }
        }

        if (border_color.is_visible()) matrix[j * 64 + x + width - 1] = border_color;
    }
}