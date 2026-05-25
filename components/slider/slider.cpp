#include "slider.hpp"

#include <iostream>

void Slider::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    Point end(start.x + length - 1, start.y);
    Line line (start, end, primary);
    line.render_component(matrix);

    if (max == min) {
        return;
    }

    int x_pos = start.x + static_cast<int>(std::round((float(progress) / float(max - min)) * float(length - 1)));
    if (matrix_in_bounds(x_pos, start.y)) {
        matrix[matrix_index(x_pos, start.y)] = secondary;
    }
}

void Slider::set_progress(int new_progress) {
    progress = new_progress;
}

            