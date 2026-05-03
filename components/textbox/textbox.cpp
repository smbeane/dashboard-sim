#include "textbox.hpp"

void Textbox::render_component(std::array<Color, 64*32>& matrix) {
    int box_length = text.length() > length ? length : text.length();
    int dx = this->x;
    int dy = this->y;

    std::string::const_iterator curr_char = scroll_start;

    for (int c = 0; c < box_length; c++) {
        if (text.empty()) break;
        uint16_t character = font_3x5[*curr_char - 32];
        uint16_t mask = 0x4000; 

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 3; col++) {
                int px = dx + col;
                int py = dy + row;

                if (px >= 0 && px < 64 && py >= 0 && py < 32) {
                    int pixel_index = (py * 64) + px;
                    matrix[pixel_index] = (character & mask) ? primary : secondary;
                }
                mask >>= 1;
            }
        }

        curr_char++;
        if (curr_char == text.end()) {
            curr_char = text.begin();
        }

        dx += 4;
    }
}
    
void Textbox::swap_text(std::string new_text) {
    text.clear();

    for (char c : new_text) {
        text.push_back(std::toupper(c));
    }

    scroll_start = text.begin();
}

void Textbox::scroll_text() {
    if (text.empty()) return;

    scroll_start++;
    if (scroll_start == text.end()) {
        scroll_start = text.begin();
    }
}    

            