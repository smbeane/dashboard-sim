#pragma once

#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <cmath> 
#include "../component.hpp"

class Progress_bar : public Component {
    public: 
        
        // define additional variables and add to constructor
        int width, height;
        int progress;

        Progress_bar (int x, int y, int width, int height, int progress, Color b, Color i) 
        :  Component(x, y, b, i), width(width), height(height), progress(progress)
        {}

        void render_component(std::array<Color, 64*32>& matrix) override;
        void update_progress(int new_progress);

        // define component specific functions
    private: 
};

#endif // PROGRESS_BAR_HPP
                