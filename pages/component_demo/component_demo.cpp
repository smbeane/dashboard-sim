#include "component_demo.hpp"

void ComponentPage::init_page() {
    components.push_back(std::make_unique<Rectangle>(Point(3, 3), 10, 10, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<Line>(Point(15, 3), Point(24, 12), PROFILE_COLOR));
    components.push_back(std::make_unique<Circle>(Point(32, 8), 5, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<ProgressBar>(Point(40, 4), 20, 5, 50, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<Slider>(Point(40, 12), 20, 0, 100, 49, true, WHITE, PROFILE_COLOR));
    components.push_back(std::make_unique<TextBox>(Point(5, 17), "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 'l', 2, PROFILE_COLOR, BLACK));
    components.push_back(std::make_unique<TextBox>(Point(5, 24), " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 'l', 2, PROFILE_COLOR, BLACK));
}


void ComponentPage::update_data() {
    for (auto& comp : components) {
        if (auto* t = dynamic_cast<TextBox*>(comp.get())) {
            t->scroll_text();
        }
    }
}