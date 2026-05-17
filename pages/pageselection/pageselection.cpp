
#include "pageselection.hpp"

void PageSelectionPage::bind_actions() {
    rotary_left.bind(RotaryAction::Left, [this]() -> std::optional<int> {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == 0) selected_idx = components.size() - 1;
        else selected_idx -= 1;
    
        components[selected_idx]->change_primary(WHITE);

        return {};
    });

    rotary_left.bind(RotaryAction::Right, [this]() ->std::optional<int> {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == (components.size() - 1)) selected_idx = 0;
        else selected_idx += 1;

        components[selected_idx]->change_primary(WHITE);

        return {};
    });

    rotary_left.bind(RotaryAction::Press, [this]() -> std::optional<int> {
        return selected_idx + 1;
    });
}

void PageSelectionPage::init_page(std::vector<std::string> page_names) {
    for (int i = 0; i < page_names.size(); i++) {
        const auto& name = page_names[i];
        create_component<TextBox>(Point(2, (i * 7) + 2), name, 16, 'l', 2, UNSELECTED, BLACK);
    }

    components[selected_idx]->change_primary(WHITE);

    bind_actions();
}

void PageSelectionPage::update_data() {

}

std::optional<int> PageSelectionPage::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) return rotary_left.execute(action);
    else return rotary_right.execute(action);
}
