#pragma once

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <colors.hpp>
#include <array>

class Component {
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

        virtual ~Component() {}

        
};



#endif // COMPONENT_HPP