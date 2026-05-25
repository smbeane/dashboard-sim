#include "clock.hpp"

#include <cmath>
#include <iostream>

#define PI 3.1415

namespace {
    void update_minute_hand(Line& hand, std::string time, int x, int y) {
        int minute = std::stoi(time.substr(3, 2));
        double degree = (minute / 60.0) * 2 * PI;

        int dx = static_cast<int>(std::round(8 * cos(degree - PI / 2)));
        int dy = static_cast<int>(std::round(8 * sin(degree - PI / 2)));

        hand.set_endx(dx + x);
        hand.set_endy(dy + y);
    }

    void update_hour_hand (Line& hand, std::string time, int x, int y) {
        int hour = std::stoi(time.substr(0, 2));
        int minute = std::stoi(time.substr(3, 2));

        double degree = ((hour / 12.0) + (minute / 720.0))* 2 * PI;

        int dx = static_cast<int>(std::round(6 * cos(degree - PI / 2)));
        int dy = static_cast<int>(std::round(6 * sin(degree - PI / 2)));

        hand.set_endx(dx + x);
        hand.set_endy(dy + y);
    }
}

void Clock::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    clock.render_component(matrix);
    render_time_notches(matrix);

    minute_hand.render_component(matrix);
    hour_hand.render_component(matrix);

}

void Clock::update_time(std::string time) {
    update_minute_hand(minute_hand, time, center.x, center.y); 
    update_hour_hand(hour_hand, time, center.x, center.y);
}

void Clock::render_time_notches(std::array<Color, MATRIX_SIZE>& matrix) {
    auto set_notch = [&](int px, int py) {
        if (matrix_in_bounds(px, py)) {
            matrix[matrix_index(px, py)] = notch_color;
        }
    };

    int x = center.x;
    int y = center.y;

    set_notch(x, y - 9);
    set_notch(x - 5, y - 8);
    set_notch(x + 5, y - 8);
    set_notch(x - 8, y - 5);
    set_notch(x + 8, y - 5);
    set_notch(x - 9, y);
    set_notch(x + 9, y);
    set_notch(x - 8, y + 5);
    set_notch(x + 8, y + 5);
    set_notch(x - 5, y + 8);
    set_notch(x + 5, y + 8);
    set_notch(x, y + 9);
}
