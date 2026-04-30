#ifndef LINE_HPP
#define LINE_HPP

#include "../component.hpp"

class Line : public Component {
    public: 
        
        // define additional variables and add to constructor
        int end_x, end_y;

        Line (int x, int y, Color border, Color infill, int end_x, int end_y) 
        :  Component(x, y, border, infill), end_x(end_x), end_y(end_y)  {}

        void render_component(std::array<Color, 64*32>& matrix) override;

        // define component specific functions
};

#endif // LINE_HPP
                