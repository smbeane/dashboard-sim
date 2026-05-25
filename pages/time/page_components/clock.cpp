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
    // 12 o'clock
    int x = center.x;
    int y = center.y;
    
    matrix[(y - 9) * 64 + x] = notch_color;
    
    // 11 and 1 o'clock
    matrix[(y - 8) * 64 + (x - 5)] = notch_color;
    matrix[(y - 8) * 64 + (x + 5)] = notch_color;
    
    // 10 and 2 o'clock
    matrix[(y - 5) * 64 + (x - 8)] = notch_color;
    matrix[(y - 5) * 64 + (x + 8)] = notch_color;

    // 9 and 3 o'clock
    matrix[y * 64 + (x - 9)] = notch_color;
    matrix[y * 64 + (x + 9)] = notch_color;
    
    // 8 and 4 o'clock
    matrix[(y + 5) * 64 + (x - 8)] = notch_color;
    matrix[(y + 5) * 64 + (x + 8)] = notch_color;
    
    // 7 and 5 o'clock
    matrix[(y + 8) * 64 + (x - 5)] = notch_color;
    matrix[(y + 8) * 64 + (x + 5)] = notch_color;
    
    // 6 o'clock
    matrix[(y + 9) * 64 + x] = notch_color;

}