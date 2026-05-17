
#ifndef PAGESELECTION_HPP
#define PAGESELECTION_HPP

#include "../page.hpp"
#include <components/components.hpp>
#include <utils/inputs/rotary_encoder.hpp>

class PageSelectionPage : public Page {
    private:
        
        int selected_idx;
        RotaryEncoder rotary_left, rotary_right;

        void bind_actions();

    public:

        PageSelectionPage() : Page("PageSelectionPage") {}

        PageSelectionPage(std::string name, std::vector<std::string> page_names) : Page(name), selected_idx(0) {
            init_page(page_names);
        }

        PageSelectionPage(std::string name, std::vector<std::string> page_names, int selected_idx) : Page(name), selected_idx(selected_idx) {
            init_page(page_names);
        }

        void init_page(std::vector<std::string> page_names);
        void update_data() override;
        void execute_action(RotaryAction action, int rotary) override;
};

#endif // PAGESELECTION_HPP
