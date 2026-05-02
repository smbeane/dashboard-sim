#pragma once

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color.hpp>
#include <array>

class Component {
    public:
        int x, y;
        Color border_color;
        Color infill_color;
        bool visible;

        Component (int x, int y, Color border, Color infill) 
        : x(x), y(y), border_color(border), infill_color(infill), visible(false) {}

        void show_component() { visible = true;  }
        void hide_component() { visible = false; }

        virtual void render_component(std::array<Color, 64*32>& matrix) = 0;

        virtual ~Component() {}

        
};



#endif // COMPONENT_HPP