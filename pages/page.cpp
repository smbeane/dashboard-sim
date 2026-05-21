#include "page.hpp"

#include <pages/pageselection/pageselection.hpp>

/**
 * @brief Renders all page components into the provided matrix buffer.
 *
 * @param matrix The display matrix to draw into.
 */
void Page::render_page(std::array<Color, MATRIX_SIZE>& matrix) {
    for (auto& c : components) {
        c->render_component(matrix);
    }
}

/**
 * @brief Default page action handler.
 *
 * Returns no action unless overridden by a derived page.
 *
 * @param action Rotary action requested.
 * @param rotary Encoder index that triggered the action.
 * @return Optional result from the action.
 */
PageActionResult Page::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) return rotary_left.execute(action);
    else return {};
}

void Page::bind_actions() {
    rotary_left.bind(RotaryAction::Press, [this]() -> PageActionResult {
        return PushAction{std::make_unique<PageSelectionPage>("Page Selection", Config::page_names, name)};
    });
}