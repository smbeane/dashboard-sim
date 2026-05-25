#ifndef COMPONENT_DEMO_HPP
#define COMPONENT_DEMO_HPP

#include <string>
#include <array>
#include <optional>

#include "../page.hpp"
#include <components/components.hpp>
#include <utils/inputs/rotary_encoder.hpp>

class ComponentPage : public Page {
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

};

#endif // COMPONENT_DEMO_HPP