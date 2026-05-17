#include "line.hpp"
#include <iostream>

void Line::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    if (primary.is_transparent()) return;
    
    int x1 = this->start.x;
    int y1 = this->start.y;
    int x2 = this->end.x; 
    int y2 = this->end.y;

    int dx =  abs(x2 - x1);
    int dy = -abs(y2 - y1);
    int sx = x1 < x2 ? 1 : -1;
    int sy = y1 < y2 ? 1 : -1;
    int err = dx + dy;

    while (true) {
        if (x1 >= 0 && x1 < 64 && y1 >= 0 && y1 < 32) {
            matrix[y1 * 64 + x1] = this->primary;
        }

        if (x1 == x2 && y1 == y2) break;

        int e2 = 2 * err;
        if (e2 >= dy) { 
            err += dy; 
            x1 += sx; 
        }
        if (e2 <= dx) { 
            err += dx; 
            y1 += sy; 
        }
    }
}

            