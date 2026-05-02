#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <cmath>

#include "../component.hpp"
#include "../line/line.hpp"


class Slider : public Component {
    public: 
        
        // define additional variables and add to constructor
        int length;
        int progress;

        Slider (int x, int y, Color primary, Color secondary, int length , int progress) 
        :  Component( x, y, primary, secondary ), length(length), progress( progress )  {}

        void render_component(std::array<Color, 64*32>& matrix) override;

        // define component specific functions
};

#endif // SLIDER_HPP
                