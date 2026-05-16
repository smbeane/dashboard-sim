#ifndef COLORPICKER_HPP
#define COLORPICKER_HPP

#include <cstdint>
#include <string>
#include <array>
#include <functional>

#include <components/components.hpp>
#include <color/colors.hpp>
#include "../page.hpp"

class ColorPickerPage : public Page {
    // TODO: clean up initialization and saved variables
    public: 
        std::array<uint8_t, 3> color_vals;
        std::array<Slider*, 3> sliders;
        std::array<TextBox*, 3> textboxes;
        int curr_selected;
        
        Rectangle* picked_rect;
        
        RotaryEncoder rotary_left, rotary_right;

        /**
         * @brief 
         */
        ColorPickerPage() : Page("ColorPicker") { init_page(); };

        ColorPickerPage(std::string name, Color curr) : Page(name) { 
            color_vals = {curr.r, curr.g, curr.b};

            init_page(); 
        }; 

        /**
         * @brief 
         */
        ColorPickerPage(std::string name) : Page(name)  {}

        /**
         * @brief
         */
        void init_page() override;

        /**
         * @brief
         */
        void update_data() override;

        /**
         * @brief 
         */
        void execute_action(RotaryAction action, int rotary);

        // TODO: define page specific functions
};

#endif // COLORPICKER_HPP
