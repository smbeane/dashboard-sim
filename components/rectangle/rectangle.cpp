#include "rectangle.hpp"

void Rectangle::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    int x = pos.x;
    int y = pos.y;

    if (!primary.is_transparent()) {
        for (int i = x; i < x + width; i++) {
            if (matrix_in_bounds(i, y)) {
                matrix[matrix_index(i, y)] = primary;
            }
            if (matrix_in_bounds(i, y + height - 1)) {
                matrix[matrix_index(i, y + height - 1)] = primary;
            }
        }
    }

    for (int j = y + 1; j < y + height - 1; j++) {
        if (!primary.is_transparent() && matrix_in_bounds(x, j)) {
            matrix[matrix_index(x, j)] = primary;
        }
        
        if (!secondary.is_transparent()) {
            for (int i = x + 1; i < x + width - 1; i++) {
                if (matrix_in_bounds(i, j)) {
                    matrix[matrix_index(i, j)] = secondary;
                }
            }
        }

        if (!primary.is_transparent() && matrix_in_bounds(x + width - 1, j)) {
            matrix[matrix_index(x + width - 1, j)] = primary;
        }
    }
}
