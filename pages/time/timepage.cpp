#include "timepage.hpp"

#include <iostream>

void TimePage::init_page() {
    std::unique_ptr<Component> tb_time = std::make_unique<Textbox>(29, 3, time, 8, 2, profile_color, black);
    time_tb = static_cast<Textbox*>(tb_time.get());
    components.push_back(std::move(tb_time));

    std::unique_ptr<Component> tb_date = std::make_unique<Textbox>(27, 24, date, 9, 2, profile_color, black);
    date_tb = static_cast<Textbox*>(tb_date.get());
    components.push_back(std::move(tb_date));

    std::unique_ptr<Component> tb_year = std::make_unique<Textbox>(47, 18, year, 4, 2, profile_color, black);
    year_tb = static_cast<Textbox*>(tb_year.get());
    components.push_back(std::move(tb_year));

    std::unique_ptr<Component> clk = std::make_unique<Clock>(12, 15, profile_color, black, white, profile_color, white);
    clock = static_cast<Clock*>(clk.get());
    components.push_back(std::move(clk));

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
