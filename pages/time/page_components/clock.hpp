#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <components/components.hpp>

class Clock : public Component {
    private: 
        Point center;
        Color notch_color;    
        Line minute_hand, hour_hand;
        Circle clock;
        
        /**
         * @brief Renders the hour/minute notches around the clock face.
         *
         * @param matrix The display buffer to paint into.
         */
        void render_time_notches(std::array<Color, MATRIX_SIZE>& matrix);
    
    public:
    
    
        /**
         * @brief Constructs a clock component with border, infill, and hand colors.
         *
         * @param center The clock center in matrix coordinates.
         * @param border Color of the clock bezel.
         * @param infill Color inside the clock face.
         * @param minute_color Color of the minute hand.
         * @param hour_color Color of the hour hand.
         * @param notch_color Color of the hour notches.
         */
        Clock (Point center, Color border, Color infill, Color minute_color, Color hour_color, Color notch_color)  
        : Component(border, infill), center(center), notch_color(notch_color) {
            
            minute_hand = Line(center, center, minute_color);
            hour_hand   = Line(center, center, hour_color);
            
            clock = Circle(center, 10, border, infill);
            
        }

        /**
         * @brief Renders the clock face and hands.
         *
         * @param matrix The display buffer to paint into.
         */
        void render_component(std::array<Color, MATRIX_SIZE>& matrix) override; 
    
        /**
         * @brief Updates the displayed time from a formatted time string.
         *
         * @param time Formatted time text such as "08:45 PM".
         */
        void update_time(std::string time);
    
    private: 

};

#endif // CLOCK_HPP