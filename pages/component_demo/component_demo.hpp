#ifndef COMPONENT_DEMO_HPP
#define COMPONENT_DEMO_HPP

#include <string>
#include <array>

#include "../page.hpp"
#include <components/components.hpp>

class ComponentPage : public Page {
    public:

        ComponentPage(std::string name) : Page(name) {init_page();};

        void init_page();

        void render_page(std::array<Color, 32*64>& matrix);

        void update_data();


};

#endif // COMPONENT_DEMO_HPP