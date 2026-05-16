#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP

#include <string>
#include <fonts.hpp>

#include "../component.hpp"

class TextBox : public Component {
    // TODO: add alignment
    // TODO: if text updates to less than length, must update to clear the chars removed
    private: 
        Point pos;
        std::string::const_iterator scroll_start;
        std::string text;
        int length, scroll_gap;
        char alignment;
        
    public: 
        
        /**
         * @brief Constructs default TextBox, position (0, 0), 
         *        completely transparent with 0 length and text
         */
        TextBox () : Component( BLACK, BLACK), pos({0, 0}), text(""), length(0) {};
        

        // TODO: update to include font selections
        /** 
         * @brief Constructs a TextBox at defined 
         * 
         * @param pos The top left offset from the top left corner of screen (0-63, 0-31)
         * @param t std::string of text to be rendered
         * @param length The number of characters to be displayed at one time
         * @param alignment Character corresponding to text alignment ('l', 'c', 'r')
         * @param scroll_gap The number of 3x5 spaces between full scroll rotations
         * @param primary The Color of the text
         * @param secondary The Color of the background of the TextBox
        */
        TextBox (Point pos, std::string t, int length, char alignment, int scroll_gap, Color primary, Color secondary) 
        :  Component(primary, secondary), pos(pos), length(length), scroll_gap(scroll_gap), alignment(alignment) {
            for (char c : t) {
                text.push_back(std::toupper(c));
            }

            if (text.length() > length) {
                    text.append(scroll_gap, ' ');
            } else {
                int total = length - text.length();

                switch (alignment) {
                    case 'l': 
                        text.append(total, ' ');
                        break;
                    case 'c':
                        text.insert(0, total / 2, ' ');
                        text.append(total - (total / 2), ' ');
                        break;

                    case 'r':
                        text.insert(0, total, ' ');
                        break;
                }
                    
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
        
        /**
         * @brief Scrolls the text by one character, but does not rerender
         */
        void scroll_text(); 

};

#endif // TEXTBOX_HPP
                