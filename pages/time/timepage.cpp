#include "timepage.hpp"


void TimePage::init_page() {
    time_tb = create_component<TextBox>(Point(29, 3), time, 8, 'c', 2, primary);
    date_tb = create_component<TextBox>(Point(27, 24), date, 9, 'c', 2, primary);
    year_tb = create_component<TextBox>(Point(47, 18), year, 4, 'c', 2, primary);

    clock = create_component<Clock>(Point(12, 15), primary, BLACK, secondary, accent, GREY);

    update_data();
    bind_actions();

}

void TimePage::update_data() {
    time = get_time_str();
    time_tb->swap_text(time);

    date = get_date_str();
    date_tb->swap_text(date);

    year = get_year_str();
    year_tb->swap_text(year);

    if (clock != nullptr) clock->update_time(time);
}