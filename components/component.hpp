#pragma once

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color/colors.hpp>
#include <point/point.hpp>
#include <array>

class Component {
    // TODO: add center on page function with left or right bias
    protected: 
        Color primary;
        Color secondary;
        bool is_visible;

    public:

        Component (Color p, Color s) 
        : primary(p), secondary(s), is_visible(false) {}

        void show_component() { is_visible = true;  }
        void hide_component() { is_visible = false; }

        virtual void render_component(std::array<Color, 64*32>& matrix) = 0;

        void change_color (Color new_color) { primary = new_color; secondary = new_color; };

        void change_primary (Color new_primary) { primary = new_primary; };

        void change_secondary (Color new_secondary) { secondary = new_secondary; };


        
};



#endif // COMPONENT_HPP