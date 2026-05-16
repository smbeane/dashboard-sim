#include "slider.hpp"

void Slider::render_component(std::array<Color, 64*32>& matrix) {
    Line line (x, y, x + length - 1, y, primary);
    line.render_component(matrix);

    int x_pos = x + round((float(progress) / (max - min)) * (length - 1));
    matrix[64 * y + x_pos] = secondary;
}

void Slider::set_progress(int new_progress) {
    progress = new_progress;
}

            