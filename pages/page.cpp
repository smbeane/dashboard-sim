#include "page.hpp"

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
std::optional<int> Page::execute_action(RotaryAction action, int rotary) {
    return {};
}