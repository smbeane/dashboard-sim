#include "timepage.hpp"

#include <iostream>

const Color MinuteHand = Color(255, 110, 0, 1);
const Color Grey =  Color(120, 120, 120, 1);

void TimePage::init_page() {

    time_tb = create_component<TextBox>(Point(29, 3), time, 8, 'c', 2, PROFILE_COLOR, BLACK);
    date_tb = create_component<TextBox>(Point(27, 24), date, 9, 'c', 2, PROFILE_COLOR, BLACK);
    year_tb = create_component<TextBox>(Point(47, 18), year, 4, 'c', 2, PROFILE_COLOR, BLACK);

    clock = create_component<Clock>(Point(12, 15), PROFILE_COLOR, BLACK, WHITE, MinuteHand, Grey);

    update_data();

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
