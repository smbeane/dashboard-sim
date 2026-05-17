#ifndef COMPONENT_DEMO_HPP
#define COMPONENT_DEMO_HPP

#include <string>
#include <array>
#include <optional>

#include "../page.hpp"
#include <components/components.hpp>
#include <utils/inputs/rotary_encoder.hpp>

class ComponentPage : public Page {
    private:
        RotaryEncoder rotary_left, rotary_right;

    public:

        ComponentPage(std::string name) : Page(name) { init_page(); };

        void init_page();

        void update_data();

        void bind_actions();

        std::optional<int> execute_action(RotaryAction action, int rotary);

};

#endif // COMPONENT_DEMO_HPP