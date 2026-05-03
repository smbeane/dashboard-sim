#include "timepage.hpp"

#include <iostream>
#include <cmath>
#define PI 3.1415

namespace {
    void update_minute_hand(Line* hand, std::string time, int x, int y) {
        int minute = std::stoi(time.substr(3, 2));
        float degree = (minute / 60.0) * 2 * PI;

        int dx = 8 * cos(degree - PI / 2);
        int dy = 8 * sin(degree - PI / 2);

        hand->end_x = dx + x;
        hand->end_y = dy + y;
    }

    void get_hour_hand (Line* hand, std::string time, int x, int y) {
        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(3, 2));

        float degree = ((hour / 12.0) + (minute / 720.0))* 2 * PI;

        int dx = 6 * cos(degree - PI / 2);
        int dy = 6 * sin(degree - PI / 2);

        hand->end_x = dx + x;
        hand->end_y = dy + y;

    }
}


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

    components.push_back(std::make_unique<Circle>(12, 15, profile_color, black, 10));
    
    std::unique_ptr<Component> hand_minute = std::make_unique<Line>(12, 15, profile_color, 0, 0);
    minute_hand = static_cast<Line*>(hand_minute.get());
    components.push_back(std::move(hand_minute));

    std::unique_ptr<Component> hand_hour = std::make_unique<Line>(12, 15, white, 0, 0);
    hour_hand = static_cast<Line*>(hand_hour.get());
    components.push_back(std::move(hand_hour));


    update_data();
}

void TimePage::update_data() {
    time = get_time_str();
    time_tb->swap_text(time);

    date = get_date_str();
    date_tb->swap_text(date);

    year = get_year_str();
    year_tb->swap_text(year);

    update_minute_hand(minute_hand, time, 12, 15);
    get_hour_hand(hour_hand, time, 12, 15);
    
}
