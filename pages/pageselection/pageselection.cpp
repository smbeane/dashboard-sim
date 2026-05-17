
#include "pageselection.hpp"

void PageSelectionPage::bind_actions() {
    rotary_left.bind(RotaryAction::Left, [this]() {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == 0) selected_idx = components.size() - 1;
        else selected_idx -= 1;
    
        components[selected_idx]->change_primary(WHITE);
    });

    rotary_left.bind(RotaryAction::Right, [this]() {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == (components.size() - 1)) selected_idx = 0;
        else selected_idx += 1;

        components[selected_idx]->change_primary(WHITE);
    });

    rotary_left.bind(RotaryAction::Press, [this]() {

    });

    rotary_right.bind(RotaryAction::Left, [this]() {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == 0) selected_idx = components.size() - 1;
        else selected_idx -= 1;
    
        components[selected_idx]->change_primary(WHITE);
    });

    rotary_right.bind(RotaryAction::Right, [this]() {
        components[selected_idx]->change_primary(UNSELECTED);

        if (selected_idx == (components.size() - 1)) selected_idx = 0;
        else selected_idx += 1;

        components[selected_idx]->change_primary(WHITE);
    });

    rotary_right.bind(RotaryAction::Press, [this]() {

    });

}

void PageSelectionPage::init_page(std::vector<std::string> page_names) {
    // TODO: initialize components for PageSelectionPage
    for (int i = 0; i < page_names.size(); i++) {
        const auto& name = page_names[i];
        create_component<TextBox>(Point(2, (i * 7) + 2), name, 16, 'l', 2, UNSELECTED, BLACK);
    }

    components[selected_idx]->change_primary(WHITE);

    bind_actions();

}

void PageSelectionPage::update_data() {
    // TODO: update page state
}

void PageSelectionPage::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) rotary_left.execute(action);
    else rotary_right.execute(action);
}
