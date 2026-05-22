#include "component_demo.hpp"

void ComponentPage::init_page() {
    create_component<Rectangle>(Point(3, 3), 10, 10, primary, secondary);
    create_component<Line>(Point(15, 3), Point(24, 12), secondary);
    create_component<Circle>(Point(32, 8), 5, primary, secondary);
    create_component<ProgressBar>(Point(40, 4), 20, 5, 50, primary, secondary);
    create_component<Slider>(Point(40, 12), 20, 0, 100, 49, true, primary, secondary);
    create_component<TextBox>(Point(5, 17), "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789", 14, 'l', 2, primary);
    create_component<TextBox>(Point(5, 24), " !\"#$%&'()*+,-./'):;<=>?@[\\]^_`", 14, 'l', 2, primary);

    bind_actions();
}

void ComponentPage::update_data() {
    for (auto& comp : components) {
        if (auto* t = dynamic_cast<TextBox*>(comp.get())) {
            t->scroll_text();
        }
    }
}