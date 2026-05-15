#include "page.hpp"

void Page::render_page(std::array<Color, 32*64>& matrix) {
    for (auto& c : components) {
        c->render_component(matrix);
    }
}

void Page::execute_action(RotaryAction action) {
    
}