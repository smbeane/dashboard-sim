#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>
#include <fonts.hpp>

#include "../component.hpp"

class Textbox : public Component {
    public: 
        
        // define additional variables and add to constructor
        std::string text;
        int length;
        
        // TODO: update to include font selections
        Textbox (int x, int y, std::string t, int length, int scroll_gap, Color primary, Color secondary) 
        :  Component(x, y, primary, secondary), length(length) {
            
            for (char c : t) {
                text.push_back(std::toupper(c));
            }
            
            for (int i = 0; i < scroll_gap; i++) {
                text.push_back(' ');
            }

            scroll_start = text.begin();
            
        }
        
        void render_component(std::array<Color, 64*32>& matrix) override;
        
        void swap_text(std::string new_text);
        
        void scroll_text(); 
        
        // define component specific functions
    private:
        std::string::const_iterator scroll_start;
};

#endif // TEXTBOX_HPP
                