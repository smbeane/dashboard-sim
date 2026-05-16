#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <components/components.hpp>

class Clock : public Component {
    // TODO: add function comments
    private: 
        Point center;
        Color notch_color;    
        Line minute_hand, hour_hand;
        Circle clock;
        
        void render_time_notches(std::array<Color, 64*32>& matrix);
    
    public:
    
    
        Clock (Point center, Color border, Color infill, Color minute_color, Color hour_color, Color notch_color)  
        : Component(border, infill), center(center), notch_color(notch_color) {
            
            minute_hand = Line(center, center, minute_color);
            hour_hand   = Line(center, center, hour_color);
            
            clock = Circle(center, 10, border, infill);
            
        }

        void render_component(std::array<Color, 64*32>& matrix) override; 
    
        void update_time(std::string time);
    
    private: 

};

#endif // CLOCK_HPP