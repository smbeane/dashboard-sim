#ifndef PROGRESS_BAR_HPP
#define PROGRESS_BAR_HPP

#include <cmath> 
#include "../component.hpp"

class ProgressBar : public Component {
    private: 
        Point pos;
        int width, height;
        int progress;

    public: 
        
        /**
         * @brief Constructs default ProgressBar, position (0, 0)
         *        completely transparent with 0 width, height, or progress
         */
        ProgressBar () : Component(TRANSPARENT, TRANSPARENT), 
                         pos({0, 0}), width(0), height(0), progress(0) {}

        /**
         * @brief Constructs a ProgressBar at defined pixel location
         * 
         * @param pos The top left offset from the top left corner (0-63, 0-31)
         * @param w The width of the border (0 < w < 63 - x)
         * @param h The height of the border (0 < h < 31 - x)
         * @param progress The percentage (0 - 100) of bar to be filled
         * @param border Color of the border
         * @param infill Color of the progress infill
         */
        ProgressBar (Point pos, int width, int height, int progress, Color border, Color infill) 
        :  Component(border, infill), pos(pos), width(width), height(height), progress(progress) {}

        /**
         * @brief Renders component using two Rectangles, one with transparent
         *        infill, and the other with transparent border over top
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, MATRIX_SIZE>& matrix) override;

        /**
         * @brief Updates the progress but does not rerender
         * 
         * @param new_progress The percentage (0 - 100) of bar to be filled
         */
        void update_progress(int new_progress);

};

#endif // PROGRESS_BAR_HPP