#pragma once

#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <cmath> 
#include "../component.hpp"

class ProgressBar : public Component {
    public: 
        
        int width, height;
        int progress;

        /**
         * @brief Constructs default ProgressBar, position (0, 0)
         *        completely transparent with 0 width, height, or progress
         */
        ProgressBar () : Component(0, 0, TRANSPARENT, TRANSPARENT), 
                          width(0), height(0), progress(0) {}

        /**
         * @brief Constructs a ProgressBar at defined pixel location
         * 
         * @param x The center offset from left edge (0-63)
         * @param y The center offset from top edge (0-31)
         * @param w The width of the border (0 < w < 63 - x)
         * @param h The height of the border (0 < h < 31 - x)
         * @param progress The percentage (0 - 100) of bar to be filled
         * @param border Color of the border
         * @param infill Color of the progress infill
         */
        ProgressBar (int x, int y, int width, int height, int progress, Color border, Color infill) 
        :  Component(x, y, border, infill), width(width), height(height), progress(progress)
        {}

        /**
         * @brief Renders component using two Rectangles, one with transparent
         *        infill, and the other with transparent border over top
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;

        /**
         * @brief Updates the progress but does not rerender
         * 
         * @param new_progress Thepercentage (0 - 100) of bar to be filled
         */
        void update_progress(int new_progress);

    private: 
};

#endif // PROGRESS_BAR_HPP
                