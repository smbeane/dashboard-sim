#include "circle.hpp"

#include <iostream>

void Circle::render_component(std::array<Color, 64*32>& matrix) {
    if (secondary.is_transparent()) {
        draw_infill(matrix);
    }
    if (primary.is_transparent()) draw_border(matrix);    
}

void Circle::draw_infill(std::array<Color, 32*64>& matrix) {
    int cx = this->x;
    int cy = this->y;
    int r = this->radius;
    int x_off = 0;
    int y_off = r;
    int d = 3 - 2 * r;

    auto draw_fill_line = [&](int x1, int x2, int y_pos) {
        if (y_pos < 0 || y_pos >= 32) return;

        if (x1 > x2) std::swap(x1, x2);

        int start_x = std::max(0, x1);
        int end_x = std::min(63, x2);

        for (int i = start_x; i <= end_x; i++) {
            matrix[y_pos * 64 + i] = secondary;
        }
    };

    while (y_off >= x_off) {
        draw_fill_line(cx - x_off, cx + x_off, cy + y_off);
        draw_fill_line(cx - x_off, cx + x_off, cy - y_off);
        draw_fill_line(cx - y_off, cx + y_off, cy + x_off);
        draw_fill_line(cx - y_off, cx + y_off, cy - x_off);

        if (d < 0) d = d + 4 * x_off + 6;
        else {
            d = d + 4 * (x_off - y_off) + 10;
            y_off--;
        }
        x_off++;
    }
}

void Circle::draw_border(std::array<Color, 32*64>& matrix) {
    int cx = this->x;
    int cy = this->y;
    int r = this->radius;
    int x_off = 0;
    int y_off = r;
    int d = 3 - 2 * r;

    auto plot_border = [&](int px, int py) {
        if (px >= 0 && px < 64 && py >= 0 && py < 32) {
            matrix[py * 64 + px] = primary;
        }
    };

    while (y_off >= x_off) {
        plot_border(cx + x_off, cy + y_off);
        plot_border(cx - x_off, cy + y_off);
        plot_border(cx + x_off, cy - y_off);
        plot_border(cx - x_off, cy - y_off);
        plot_border(cx + y_off, cy + x_off);
        plot_border(cx - y_off, cy + x_off);
        plot_border(cx + y_off, cy - x_off);
        plot_border(cx - y_off, cy - x_off);

        if (d < 0) d = d + 4 * x_off + 6;
        else {
            d = d + 4 * (x_off - y_off) + 10;
            y_off--;
        }
        x_off++;
    }
}

