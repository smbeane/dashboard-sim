#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../component.hpp"

class Circle : public Component {
    private: 
        
        Point center;
        int radius;
    
        /**
         * @brief Renders the inside of the Circle, including
         *        where the border would go
         * 
         * @param matrix A reference to the pixels to be rendered
         */
        void draw_infill(std::array<Color, MATRIX_SIZE>& matrix);
        
        /**
         * @brief Renders only the border of the Circle
         * 
         * @param matrix A reference to the pixels to be rendered
         */
        void draw_border(std::array<Color, MATRIX_SIZE>& matrix);

    public: 

        /**
         * @brief Constructs default Circle, position (0, 0), 
         *        completely transparent with 0 radius
         */
        Circle () : Component(TRANSPARENT, TRANSPARENT), center({0, 0}), radius(0) {}

        /**
         * @brief Constructs a Circle at defined pixel location
         * 
         * @param center The center Point from the top left corner (0-63,0-31)
         * @param radius Radius of the outer rim
         * @param border Color of the circle border
         * @param infill Color of the circle infill
         */
        Circle (Point center,  int radius, Color border, Color infill) 
        :  Component(border, infill), center(center), radius(radius)  {}

        /**
         * @brief Renders component by first rendering infill,
         *        then rendering border over top
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, MATRIX_SIZE>& matrix) override;

};

#endif // CIRCLE_HPP