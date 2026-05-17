#include "page.hpp"

void Page::render_page(std::array<Color, MATRIX_SIZE>& matrix) {
    for (auto& c : components) {
        c->render_component(matrix);
    }
}

void Page::execute_action(RotaryAction action, int rotary) {
    // Base implementation to compile, 
    // only needs overridden if necessary
}