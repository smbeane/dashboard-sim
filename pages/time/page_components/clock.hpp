#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <components/components.hpp>

class Clock : public Component {
    public:
    
        Color notch_color;    
    
        Clock (int x, int y, Color border, Color infill, Color minute_color, Color hour_color, Color notch_color)  
        : Component(x, y, border, infill), notch_color(notch_color) {
            
            minute_hand = Line(x, y, x, y, minute_color);
            hour_hand   = Line(x, y, x, y, hour_color);
            
            clock = Circle(x, y, 10, border, infill);
            
        }
    
    
        void render_component(std::array<Color, 64*32>& matrix) override; 
    
        void update_time(std::string time);
    
    private: 

        Line minute_hand, hour_hand;
        Circle clock;
        
        void render_time_notches(std::array<Color, 64*32>& matrix);
};

#endif // CLOCK_HPP