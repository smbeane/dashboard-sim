#include "component_demo.hpp"

void ComponentPage::init_page() {
    components.push_back(std::make_unique<Rectangle>(3, 3, 10, 10, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<Line>(15, 3, 24, 12, PROFILE_COLOR));
    components.push_back(std::make_unique<Circle>(32, 8, 5, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<ProgressBar>(40, 4, 20, 5, 50, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<Slider>(40, 12, 20, 0, 100, 49, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<TextBox>(5, 17, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 2, PROFILE_COLOR, BLACK));
    components.push_back(std::make_unique<TextBox>(5, 24, " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 2, PROFILE_COLOR, BLACK));
}


void ComponentPage::update_data() {
    for (int i = 0; i < components.size(); i++) {

        TextBox* t = dynamic_cast<TextBox*>(components[i].get());
        if (t) t->scroll_text();
        
    }
}