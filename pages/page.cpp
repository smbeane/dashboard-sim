#include "page.hpp"

#include <pages/pageselection/pageselection.hpp>

void Page::render_page(std::array<Color, MATRIX_SIZE>& matrix) {
    for (auto& c : components) {
        c->render_component(matrix);
    }
}

void Page::update_data() {
    
}

void Page::bind_actions() {
    rotary_left.bind(RotaryAction::Press, [this]() -> PageActionResult {
        return PushAction{std::make_unique<PageSelectionPage>("Page Selection", Config::page_names, name)};
    });
}

PageActionResult Page::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) return rotary_left.execute(action);
    else return rotary_right.execute(action);
}