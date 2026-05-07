#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>
#include <fonts.hpp>

#include "../component.hpp"

class Textbox : public Component {
    public: 
        
        std::string text;
        int length;
        
        /**
         * @brief Constructs default Textbox, position (0, 0), 
         *        completely transparent with 0 length and text
         */
        Textbox () : Component(0, 0, black, black), text(""), length(0) {};
        
        // TODO: update to include font selections
        /** 
         * @brief
         * 
         * @param x The horizontal offset from the left edge of Textbox to the left edge of screen (0-63)
         * @param y The vertical offset from the top edge of Textbox to the top edge of screen (0-31)
         * @param t std::string of text to be rendered
         * @param length The number of characters to be displayed at one time
         * @param scroll_gap The number of 3x5 spaces between full scroll rotations
         * @param primary The Color of the text
         * @param secondary The Color of the background of the Textbox
        */
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
        
        /**
         * @brief Renders component (currently using default font)
         * 
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;
        
        /**
         * @brief Swaps the current text with new text, but does not rerender
         * 
         * @param new_text std::string of new text to be rendered
         */
        void swap_text(std::string new_text);
        
        // TODO: update to be able to scroll n letters at once
        /**
         * @brief Scrolls the text by one character, but does not rerender
         */
        void scroll_text(); 
    private:

        std::string::const_iterator scroll_start;
};

#endif // TEXTBOX_HPP
                