#ifndef LINE_HPP
#define LINE_HPP

#include "../component.hpp"

class Line : public Component {
    public: 
        
        // define additional variables and add to constructor
        int end_x, end_y;
        
        Line () : Component(0, 0, black, black), end_x(0), end_y(0) {}

        Line (int x, int y, Color p, int end_x, int end_y) 
        :  Component(x, y, p, Color(1, 1, 1, 1)), end_x(end_x), end_y(end_y)  {}

        void render_component(std::array<Color, 64*32>& matrix) override;

        // define component specific functions
};

#endif // LINE_HPP
                