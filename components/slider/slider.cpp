#include "slider.hpp"



void Slider::render_component(std::array<Color, 64*32>& matrix) {
    Line line (x, y, primary, x + length - 1, y);
    line.render_component(matrix);

    int x_pos = x + round(progress * (length - 1) / 100);
    matrix[64 * y + x_pos] = secondary;
    // matrix[64 * (y - 1) + x_pos] = infill_color;
    // matrix[64 * (y + 1) + x_pos] = infill_color;
}

            