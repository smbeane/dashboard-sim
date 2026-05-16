#pragma once

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color/colors.hpp>
#include <array>

class Component {
    // TODO: for all components, update public and private standings
    // TODO: add get and set methods for all variables
    public:
        int x, y;
        Color primary;
        Color secondary;
        bool visible;

        Component (int x, int y, Color p, Color s) 
        : x(x), y(y), primary(p), secondary(s), visible(false) {}

        void show_component() { visible = true;  }
        void hide_component() { visible = false; }

        virtual void render_component(std::array<Color, 64*32>& matrix) = 0;

        void change_primary (Color new_primary) { primary = new_primary; };

        void change_secondary (Color new_secondary) { secondary = new_secondary; };


        
};



#endif // COMPONENT_HPP