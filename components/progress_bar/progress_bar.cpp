#include "progress_bar.hpp"
#include "../rectangle/rectangle.hpp"

#include <cmath>

void ProgressBar::render_component(std::array<Color, 64*32>& matrix) {
    Rectangle border(pos, width, height, primary, Color(0, 0, 0, 0));
    Rectangle infill(pos, round(progress * (width - 2) / 100) + 2, height, Color(0, 0, 0, 0), secondary);

    border.render_component(matrix);
    infill.render_component(matrix);
}

void ProgressBar::update_progress(int new_progress) {
    progress = new_progress;
}

            