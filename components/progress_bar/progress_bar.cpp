#include "progress_bar.hpp"
#include "../rectangle/rectangle.hpp"

#include <cmath>

void Progress_bar::render_component(std::array<Color, 64*32>& matrix) {
    Rectangle border(x, y, width, height, primary, Color(0, 0, 0, 0));
    Rectangle infill(x, y, round(progress * (width - 2) / 100) + 2, height, Color(0, 0, 0, 0), secondary);

    border.render_component(matrix);
    infill.render_component(matrix);
}

void Progress_bar::update_progress(int new_progress) {
    progress = new_progress;
}

            