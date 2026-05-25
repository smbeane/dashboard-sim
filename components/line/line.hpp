#ifndef LINE_HPP
#define LINE_HPP

#include <cmath> 

#include "../component.hpp"

class Line : public Component {
    private: 
    
        Point start, end;
    
    public: 
        
        /**
         * @brief Constructs default Line, position (0, 0) ,
         *        completely transparent with no length
         */
        Line () : Component(BLACK, BLACK), start({0, 0}), end({0, 0}) {}

        /**
         * @brief Constructs a Line at defined pixel start and end locations
         * 
         * @param start The starting point from the top left corner (0-63, 0-31)
         * @param end The ending point from the top left corner (0-63, 0-31)
         * @param primary Color of the line
         */
        Line (Point start, Point end, Color primary) 
        :  Component(primary, TRANSPARENT), start(start), end(end) {}

        /**
         * @brief Renders component using Bresenham's Line Algorithm
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, MATRIX_SIZE>& matrix) override;

        /**
         * @brief Returns ending x coordinate of the Line
         */
        int get_endx() const { return end.x; };

        /**
         * @brief Updates ending x coordinate of the Line
         * 
         * @param new_x The new ending x coordinate of the Line (0-63)
         */
        void set_endx(int new_x) { end.x = new_x; };

        /**
         * @brief Returns ending y coordinate of the Line
         */
        int get_endy() const { return end.y; };

        /**
         * @brief Updates ending y coordinate of the Line
         * 
         * @param new_y The new ending y coordinate of the Line (0-31)
         */
        void set_endy(int new_y) { end.y = new_y; };

};

#endif // LINE_HPP