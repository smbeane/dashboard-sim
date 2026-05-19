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

        ComponentPage(std::string name, Profile p) : Page(name, p) { init_page(); };


        /**
         * @brief Creates demo components for the component showcase page.
         */
        void init_page();

        /**
         * @brief Updates dynamic demo components each frame.
         */
        void update_data();

        /**
         * @brief Binds input actions for the component demo page.
         */
        void bind_actions();

        /**
         * @brief Executes a rotary action for the component demo page.
         *
         * @param action The rotary action to handle.
         * @param rotary Which encoder index triggered the action.
         * @return Optional output value from the action.
         */
        std::optional<int> execute_action(RotaryAction action, int rotary);

};

#endif // COMPONENT_DEMO_HPP