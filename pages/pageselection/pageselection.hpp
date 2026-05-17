
#ifndef PAGESELECTION_HPP
#define PAGESELECTION_HPP

#include "../page.hpp"

class PageSelectionPage : public Page {
public:
    PageSelectionPage() : Page("PageSelectionPage") {}

    PageSelectionPage(std::string name) : Page(name) {}

    void init_page() override;
    void update_data() override;
    void execute_action(RotaryAction action, int rotary) override;
};

#endif // PAGESELECTION_HPP
