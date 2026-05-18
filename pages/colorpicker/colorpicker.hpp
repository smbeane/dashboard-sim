#ifndef COLORPICKER_HPP
#define COLORPICKER_HPP

#include <cstdint>
#include <string>
#include <array>
#include <functional>
#include <optional>

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
         * @brief Constructs the default color picker page with black initial color.
         */
        ColorPickerPage() : Page("ColorPicker"), chosen(BLACK) { init_page(); };

        /**
         * @brief Constructs a color picker page using the specified page name.
         */
        ColorPickerPage(std::string name) : Page(name), chosen(BLACK) { init_page(); };
        
        /**
         * @brief Constructs a color picker page with an initial chosen color.
         */
        ColorPickerPage(std::string name, Color curr) : Page(name), chosen(curr) { init_page(); }; 
        

        /**
         * @brief Creates the color picker components and binds input actions.
         */
        void init_page();

        /**
         * @brief Updates page state each frame (currently no periodic updates).
         */
        void update_data() override;

        /**
         * @brief Executes color picker rotary input actions.
         *
         * @param action Rotary action to perform.
         * @param rotary Which encoder index triggered the action.
         * @return Optional integer output for navigation.
         */
        std::optional<int> execute_action(RotaryAction action, int rotary);

};

#endif // COLORPICKER_HPP
