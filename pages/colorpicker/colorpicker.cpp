#include "colorpicker.hpp"

#include <iostream>

void ColorPickerPage::init_page() {
    create_component<TextBox>(Point(8, 2), "Color Picker", 12, 'c', 0, WHITE, BLACK);

    sliders[0] = create_component<Slider>(Point(2, 12), 20, 0, 255, chosen.r, true, WHITE, Color(255, 0, 0));
    sliders[1] = create_component<Slider>(Point(2, 19), 20, 0, 255, chosen.g, true, UNSELECTED, Color(0, 255, 0));
    sliders[2] = create_component<Slider>(Point(2, 26), 20, 0, 255, chosen.b, true, UNSELECTED, Color(0, 0, 255));
    
    textboxes[0] = create_component<TextBox>(Point(24, 10), std::to_string(chosen.r), 3, 'r', 0, WHITE, BLACK);
    textboxes[1] = create_component<TextBox>(Point(24, 17), std::to_string(chosen.g), 3, 'r', 0, UNSELECTED, BLACK);
    textboxes[2] = create_component<TextBox>(Point(24, 24), std::to_string(chosen.b), 3, 'r', 0, UNSELECTED, BLACK);

    picked_rect = create_component<Rectangle>(Point(39, 9), 21, 21, chosen);
    
    curr_selected = 0;

    bind_actions();

}

void ColorPickerPage::bind_actions() {
    rotary_left.bind(RotaryAction::Left, [this]() -> std::optional<int> {
        sliders[curr_selected]->change_primary(UNSELECTED);
        textboxes[curr_selected]->change_primary(UNSELECTED);
        
        if (curr_selected > 0) curr_selected -= 1;
        else curr_selected = 2;
        
        sliders[curr_selected]->change_primary(WHITE);
        textboxes[curr_selected]->change_primary(WHITE);

        return {};
    });
    
    rotary_left.bind(RotaryAction::Right, [this]() -> std::optional<int>{
        sliders[curr_selected]->change_primary(UNSELECTED);
        textboxes[curr_selected]->change_primary(UNSELECTED);
        
        if (curr_selected < 2) curr_selected += 1;
        else curr_selected = 0;
        
        sliders[curr_selected]->change_primary(WHITE);
        textboxes[curr_selected]->change_primary(WHITE);

        return {};
    });

    rotary_left.bind(RotaryAction::Press, [this]() -> std::optional<int>{
        return 0;
    });
    
    rotary_right.bind(RotaryAction::Left, [this]() -> std::optional<int>{
        int progress = sliders[curr_selected]->decrement_slider();
        update_color(progress);

        return {};
    });
    
    rotary_right.bind(RotaryAction::Right, [this]() -> std::optional<int> {
        int progress = sliders[curr_selected]->increment_slider();
        update_color(progress);

        return {};
    });
}

void ColorPickerPage::update_color(int progress) {
    textboxes[curr_selected]->swap_text(std::to_string(progress));

    switch (curr_selected) {
        case 0: chosen.r = progress; break;
        case 1: chosen.g = progress; break;
        case 2: chosen.b = progress; break;
    }
    
    picked_rect->change_color(chosen);
}

void ColorPickerPage::update_data() {

}  

std::optional<int> ColorPickerPage::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) return rotary_left.execute(action);
    else return rotary_right.execute(action);
    
}

