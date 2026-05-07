#ifndef LINE_HPP
#define LINE_HPP

#include "../component.hpp"

class Line : public Component {
    public: 
        
        int end_x, end_y;
        
        /**
         * @brief Constructs default Line, position (0, 0) ,
         *        completely transparent with no length
         */
        Line () : Component(0, 0, black, black), end_x(0), end_y(0) {}

        /**
         * @brief Constructs a Line at defined pixel start and end locations
         * 
         * @param start_x The horizontal offset from the left edge (0-63)
         * @param start_y The vertical offset from the top edge (0-31)
         * @param end_x The horizontal offset from the left edge (0-63)
         * @param end_y The vertical offset from the top edge (0-31)
         * @param primary Color of the line
         */
        Line (int start_x, int start_y, int end_x, int end_y, Color primary) 
        :  Component(start_x, start_y, primary, transparent), end_x(end_x), end_y(end_y)  {}

        /**
         * @brief Renders component using Bresenham's Line Algorithm
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;

};

#endif // LINE_HPP
                