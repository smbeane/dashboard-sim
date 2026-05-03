#include "component_demo.hpp"

void ComponentPage::init_page() {
    components.push_back(std::make_unique<Rectangle>(3, 3, 10, 10, white, profile_color));
    components.push_back(std::make_unique<Line>(15, 3, profile_color, 24, 12));
    components.push_back(std::make_unique<Circle>(32, 8, white, profile_color, 5));
    components.push_back(std::make_unique<Progress_bar>(40, 4, 20, 5, 50, white, profile_color));
    components.push_back(std::make_unique<Slider>(40, 12, white, profile_color, 20, 6));
    components.push_back(std::make_unique<Textbox>(5, 17, "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 2, profile_color, black));
    components.push_back(std::make_unique<Textbox>(5, 24, " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 2, profile_color, black));
}


void ComponentPage::update_data() {
    for (int i = 0; i < components.size(); i++) {

        Textbox* t = dynamic_cast<Textbox*>(components[i].get());
        if (t) t->scroll_text();
        
    }
}