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

        void update_data();


};

#endif // COMPONENT_DEMO_HPP