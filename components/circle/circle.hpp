#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "../component.hpp"

class Circle : public Component {
    public: 

        int radius;

        /**
         * @brief Constructs default Circle, position (0, 0), 
         *        completely transparent with 0 radius
         */
        Circle () : Component(0, 0, transparent, transparent), radius(0) {}

        /**
         * @brief Constructs a Circle at defined pixel location
         * 
         * @param x The center offset from left edge (0-63)
         * @param y The center offset from top edge (0-31)
         * @param radius Radius of the outer rim
         * @param border Color of the circle border
         * @param infill Color of the circle infill
         */
        Circle (int x, int y,  int radius, Color border, Color infill) 
        :  Component(x, y, border, infill), radius(radius)  {}

        /**
         * @brief Renders component by first rendering infill,
         *        then rendering border over top
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;

    private:
        void draw_infill(std::array<Color, 64*32>& matrix, Color fill);
        
        void draw_border(std::array<Color, 64*32>& matrix, Color border);
        
};

#endif // CIRCLE_HPP
                