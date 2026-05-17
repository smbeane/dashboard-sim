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
    private:
        Color chosen;
        std::array<Slider*, 3> sliders;
        std::array<TextBox*, 3> textboxes;
        int curr_selected;

        Rectangle* picked_rect;
        RotaryEncoder rotary_left, rotary_right;

        void bind_actions();

        void update_color(int progress);

    public: 
        /**
         * @brief 
         */
        ColorPickerPage() : Page("ColorPicker"), chosen(BLACK) { init_page(); };

        /**
         * @brief
         */
        ColorPickerPage(std::string name, Color curr) : Page(name), chosen(curr) { init_page(); }; 

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

};

#endif // COLORPICKER_HPP
