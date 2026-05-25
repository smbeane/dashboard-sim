
#ifndef PAGESELECTION_HPP
#define PAGESELECTION_HPP

#include <optional>
#include <vector>
#include <string>
#include <algorithm>

#include "../page.hpp"
#include <components/components.hpp>
#include <utils/inputs/rotary_encoder.hpp>

// TODO: change to just SelectionPage or similar

class PageSelectionPage : public Page {
    private:
        
        size_t selected_idx;
        size_t initial_idx;

        /**
         * @brief Binds all given actions to their corresponding function
         */
        void bind_actions();

    public:

        PageSelectionPage(std::string name, std::vector<std::string> page_names) : Page(name), selected_idx(0) {
            init_page(page_names);
        }

        PageSelectionPage(std::string name, std::vector<std::string> page_names, size_t selected_idx) : Page(name), selected_idx(selected_idx), initial_idx(selected_idx) {
            init_page(page_names);
        }

        PageSelectionPage(std::string name, std::vector<std::string> page_names, std::string selected_name) : Page(name) {
            std::vector<std::string>::iterator it = std::find(page_names.begin(), page_names.end(), selected_name);
            
            if (it == page_names.end()) selected_idx = initial_idx = 0;
            else selected_idx = initial_idx = static_cast<int>(distance(page_names.begin(), it));

            init_page(page_names);
        }

        /**
         * @brief Initializes the page selection UI with the available pages.
         *
         * @param page_names List of page names to display.
         */
        void init_page(std::vector<std::string> page_names);

};

#endif // PAGESELECTION_HPP
