#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../component.hpp"

class Circle : public Component {
    public: 
        
        // define additional variables and add to constructor
        int radius;

        Circle (int x, int y, Color b, Color i, int radius) 
        :  Component(x, y, b, i), radius(radius)  {}

        void render_component(std::array<Color, 64*32>& matrix) override;

        // define component specific functions

    private:
        void draw_infill(std::array<Color, 64*32>& matrix, Color fill);
        
        void draw_border(std::array<Color, 64*32>& matrix, Color border);
        
};

#endif // CIRCLE_HPP
                