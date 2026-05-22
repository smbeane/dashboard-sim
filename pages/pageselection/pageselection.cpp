#include "pageselection.hpp"

#include <iostream>

void PageSelectionPage::init_page(std::vector<std::string> page_names) {
    for (int i = 0; i < page_names.size(); i++) {
        const auto& name = page_names[i];
        create_component<TextBox>(Point(2, (i * 7) + 2), name, 16, 'l', 2, UNSELECTED, BLACK);
    }

    components[selected_idx]->change_primary(WHITE);

    bind_actions();
}

void PageSelectionPage::bind_actions() {
    rotary_left.bind(RotaryAction::Left, [this]() -> PageActionResult {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == 0) selected_idx = components.size() - 1;
        else selected_idx -= 1;
        
        components[selected_idx]->change_primary(WHITE);

        return {};
    });

    rotary_left.bind(RotaryAction::Right, [this]() -> PageActionResult {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == (components.size() - 1)) selected_idx = 0;
        else selected_idx += 1;

        components[selected_idx]->change_primary(WHITE);

        return {};
    });

    rotary_left.bind(RotaryAction::Press, [this]() -> PageActionResult {
        if (selected_idx == initial_idx) return PopAction();
        else return NavigateAction(selected_idx + 1);
    });

    rotary_right.bind(RotaryAction::Press, [this]() -> PageActionResult {
        return PopAction();
    });
}

