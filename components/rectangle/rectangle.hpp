#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../component.hpp"

class Rectangle : public Component {
    // TODO: add singular color rectangle and change_color function
    public: 
        int width, height;

        /**
         * @brief Constructs default rectangle, position (0, 0),
         *        completely transparent with 0 width or height
         */
        Rectangle() : Component(0, 0, TRANSPARENT, TRANSPARENT), width(0), height(0) {} 

        /**
         * @brief Construct a Rectangle at a defined pixel location
         * 
         * @param x The center offset from left edge (0-63)
         * @param y The center offset from top edge (0-31)
         * @param w The width of the border (0 < w < 63 - x)
         * @param h The height of the border (0 < h < 31 - x)
         * @param border Color of the border
         * @param infill Color of the infill
         */
        Rectangle(int x, int y, int w, int h, Color border, Color infill) 
        :  Component(x, y, border, infill), width(w), height(h) {}

        /**
         * @brief Renders component top working downward
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;
};

#endif // RECTANGLE_HPP