#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../component.hpp"

class Rectangle : public Component {
    public: 
        int width, height;

        Rectangle(int x, int y, int w, int h, Color border, Color infill) 
        :  Component(x, y, border, infill), width(w), height(h) {}

        void render_component(std::array<Color, 64*32>& matrix) override;
};




#endif // RECTANGLE_HPP