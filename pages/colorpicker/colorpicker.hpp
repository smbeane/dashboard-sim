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

        /**
         * @brief Binds all given actions to their corresponding function
         */
        void bind_actions();


        /**
         * @brief Updates the text corresponding to slider and 
         *        the Rectangle showing the selected color.
         *        To be used by the action lambda functions
         * 
         * @param progress The integer on the selected slider (0-255)
         */
        void update_color(int progress);

    public: 
        /**
         * @brief Constructs the default color picker page with black initial color.
         */
        ColorPickerPage() : Page("Color Picker"), chosen(BLACK) { init_page(); };

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

};

#endif // COLORPICKER_HPP
