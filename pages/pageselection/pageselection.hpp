
#ifndef PAGESELECTION_HPP
#define PAGESELECTION_HPP

#include <optional>
#include <vector>
#include <string>
#include <algorithm>

#include "../page.hpp"
#include <components/components.hpp>
#include <utils/inputs/rotary_encoder.hpp>

class PageSelectionPage : public Page {
    private:
        
        int selected_idx;
        int initial_idx;
        RotaryEncoder rotary_left, rotary_right;

        void bind_actions();

    public:

        PageSelectionPage(std::string name, std::vector<std::string> page_names) : Page(name), selected_idx(0) {
            init_page(page_names);
        }

        PageSelectionPage(std::string name, std::vector<std::string> page_names, int selected_idx) : Page(name), selected_idx(selected_idx), initial_idx(selected_idx) {
            init_page(page_names);
        }

        PageSelectionPage(std::string name, std::vector<std::string> page_names, std::string selected_name) : Page(name) {
            std::vector<std::string>::iterator it = std::find(page_names.begin(), page_names.end(), selected_name);
            
            if (it == page_names.end()) selected_idx = initial_idx = 0;
            else selected_idx = initial_idx = distance(page_names.begin(), it);

            init_page(page_names);
        }

        /**
         * @brief Initializes the page selection UI with the available pages.
         *
         * @param page_names List of page names to display.
         */
        void init_page(std::vector<std::string> page_names);

        void render_page(std::array<Color, MATRIX_SIZE>& matrix);

        /**
         * @brief Updates page selection state (no dynamic content currently).
         */
        void update_data() override;

        /**
         * @brief Executes the page selection rotary actions.
         *
         * @param action The selected rotary action.
         * @param rotary Which encoder index triggered the action.
         * @return Optional selected page index.
         */
        PageActionResult execute_action(RotaryAction action, int rotary) override;
};

#endif // PAGESELECTION_HPP
