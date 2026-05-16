#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../component.hpp"

class Rectangle : public Component {
    private: 

        Point pos;
        int width, height;
    
    public: 

        /**
         * @brief Constructs default rectangle, position (0, 0),
         *        completely transparent with 0 width or height
         */
        Rectangle() : Component(TRANSPARENT, TRANSPARENT), pos({0, 0}), width(0), height(0) {} 

        /**
         * @brief Constructs a Rectangle at defined pixel location
         *        with uniform color
         * 
         * @param pos The top left offset from top left corner (0-63, 0-31)
         * @param w The width of the border (0 < w < 63 - x)
         * @param h The height of the border (0 < h < 31 - x)
         * @param color
         */
        Rectangle(Point pos, int w, int h, Color color) 
        :  Component(color, color), pos(pos), width(w), height(h) {}

        /**
         * @brief Construct a Rectangle at a defined pixel location
         *        with separte border and infill color
         * 
         * @param pos The top left offset from the top left corner (0-63, 0-31)
         * @param w The width of the border (0 < w < 63 - x)
         * @param h The height of the border (0 < h < 31 - x)
         * @param border Color of the border
         * @param infill Color of the infill
         */
        Rectangle(Point pos, int w, int h, Color border, Color infill) 
        :  Component(border, infill), pos(pos), width(w), height(h) {}

        /**
         * @brief Renders component top working downward
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;
};

#endif // RECTANGLE_HPP