#include "slider.hpp"

void Slider::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    Point end(start.x + length - 1, start.y);

    Line line (start, end, primary);
    line.render_component(matrix);

    int x_pos = start.x + static_cast<int>(round(((progress * 1.0) / float(max - min)) * float(length - 1)));
    matrix[64 * start.y + x_pos] = secondary;
}

void Slider::set_progress(int new_progress) {
    progress = new_progress;
}

            