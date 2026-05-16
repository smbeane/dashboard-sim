#include "colorpicker.hpp"

#include <iostream>

void ColorPickerPage::init_page() {
    std::unique_ptr<Component> tb_title = std::make_unique<TextBox>(8, 2, "Color Picker", 12, 0, WHITE, BLACK);
    components.push_back(std::move(tb_title));

    std::unique_ptr<Component> slider_r = std::make_unique<Slider>(2, 12, 20, 0, 255, chosen.r, WHITE, Color(255, 0, 0));
    std::unique_ptr<Component> slider_g = std::make_unique<Slider>(2, 19, 20, 0, 255, chosen.g, Color(80, 80, 80), Color(0, 255, 0));
    std::unique_ptr<Component> slider_b = std::make_unique<Slider>(2, 26, 20, 0, 255, chosen.b, Color(80, 80, 80), Color(0, 0, 255));
    sliders[0] = static_cast<Slider*>(slider_r.get());
    sliders[1] = static_cast<Slider*>(slider_g.get());
    sliders[2] = static_cast<Slider*>(slider_b.get());
    components.push_back(std::move(slider_r));
    components.push_back(std::move(slider_g));
    components.push_back(std::move(slider_b));
    
    std::unique_ptr<Component> tb_r = std::make_unique<TextBox>(24, 10, std::to_string(chosen.r), 3, 0, WHITE, BLACK);
    std::unique_ptr<Component> tb_g = std::make_unique<TextBox>(24, 17, std::to_string(chosen.g), 3, 0, Color(80, 80, 80), BLACK);
    std::unique_ptr<Component> tb_b = std::make_unique<TextBox>(24, 24, std::to_string(chosen.b), 3, 0, Color(80, 80, 80), BLACK);
    textboxes[0] = static_cast<TextBox*>(tb_r.get());
    textboxes[1] = static_cast<TextBox*>(tb_g.get());
    textboxes[2] = static_cast<TextBox*>(tb_b.get());
    components.push_back(std::move(tb_r));
    components.push_back(std::move(tb_g));
    components.push_back(std::move(tb_b));

    curr_selected = 0;

    std::unique_ptr<Component> rect_picked = std::make_unique<Rectangle>(39, 9, 21, 21, chosen);
    picked_rect = static_cast<Rectangle*>(rect_picked.get());
    components.push_back(std::move(rect_picked));


    rotary_left.bind(RotaryAction::Left, [this]() {
        std::cout << "Left rotating left" << std::endl;

        sliders[curr_selected]->decrement_slider();
        textboxes[curr_selected]->swap_text(std::to_string(sliders[curr_selected]->get_progress()));

        if (curr_selected == 0) chosen.r = sliders[curr_selected]->get_progress();
        if (curr_selected == 1) chosen.g = sliders[curr_selected]->get_progress();
        if (curr_selected == 2) chosen.b = sliders[curr_selected]->get_progress();

        picked_rect->change_color(chosen);
    });

    rotary_left.bind(RotaryAction::Right, [this]() {
        std::cout << "Left rotating left" << std::endl;

        sliders[curr_selected]->increment_slider();
        textboxes[curr_selected]->swap_text(std::to_string(sliders[curr_selected]->get_progress()));

        if (curr_selected == 0) chosen.r = sliders[curr_selected]->get_progress();
        if (curr_selected == 1) chosen.g = sliders[curr_selected]->get_progress();
        if (curr_selected == 2) chosen.b = sliders[curr_selected]->get_progress();

        picked_rect->change_color(chosen);
    });

    // no binding for now
    rotary_left.bind(RotaryAction::Press, [this]() {

    });

    rotary_right.bind(RotaryAction::Left, [this]() {
        std::cout << "Right rotating left" << std::endl;

        sliders[curr_selected]->change_primary(Color(80, 80, 80));
        textboxes[curr_selected]->change_primary(Color(80, 80, 80));

        if (curr_selected > 0) curr_selected -= 1;
        else curr_selected = 2;

        sliders[curr_selected]->change_primary(WHITE);
        textboxes[curr_selected]->change_primary(WHITE);


    });

    rotary_right.bind(RotaryAction::Right, [this]() {
        std::cout << "Right rotating Right" << std::endl;

        sliders[curr_selected]->change_primary(Color(80, 80, 80));
        textboxes[curr_selected]->change_primary(Color(80, 80, 80));

        if (curr_selected < 2) curr_selected += 1;
        else curr_selected = 0;

        sliders[curr_selected]->change_primary(WHITE);
        textboxes[curr_selected]->change_primary(WHITE);
    });

    // no binding for now
    rotary_right.bind(RotaryAction::Press, [this]() {

    });

    

}

void ColorPickerPage::update_data() {

}  

void ColorPickerPage::execute_action(RotaryAction action, int rotary) {
    if (rotary == 0) rotary_left.execute(action);
    else rotary_right.execute(action);
    
}

