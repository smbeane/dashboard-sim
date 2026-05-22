#include "textbox.hpp"

void TextBox::init_component(std::string t) {
    for (char c : t) {
                text.push_back(std::toupper(c));
            }

            if (text.length() > length) {
                    text.append(scroll_gap, ' ');
            } else {
                int total = length - text.length();

                switch (alignment) {
                    case 'l': 
                        text.append(total, ' ');
                        break;
                    case 'c':
                        text.insert(0, total / 2, ' ');
                        text.append(total - (total / 2), ' ');
                        break;

                    case 'r':
                        text.insert(0, total, ' ');
                        break;
                }
                    
            }


            scroll_start = text.begin();
}

void TextBox::render_component(std::array<Color, MATRIX_SIZE>& matrix) {
    int box_length = text.length() > length ? length : text.length();
    int dx = this->pos.x;
    int dy = this->pos.y;

    std::string::const_iterator curr_char = scroll_start;

    for (int c = 0; c < box_length; c++) {
        if (text.empty()) break;
        uint16_t character = font_3x5[*curr_char - 32];

        // bit position for 5x3 font rendering (bit 15)
        uint16_t mask = 0x4000; 

        for (int row = 0; row < 5; row++) {
            for (int col = 0; col < 3; col++) {
                int px = dx + col;
                int py = dy + row;

                if (matrix_in_bounds(px, py)) {
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
    
void TextBox::swap_text(std::string new_text) {
    text.clear();

    for (char c : new_text) {
        text.push_back(std::toupper(c));
    }

    if (text.length() > length) {
            text.append(scroll_gap, ' ');
    } else {
        int total = length - text.length();

        switch (alignment) {
            case 'l': 
                text.append(total, ' ');
                break;
            case 'c':
                text.insert(0, total / 2, ' ');
                text.append(total - (total / 2), ' ');
                break;

            case 'r':
                text.insert(0, total, ' ');
                break;
        }
            
    }

    scroll_start = text.begin();
}

void TextBox::scroll_text() {
    if (text.empty()) return;

    scroll_start++;
    if (scroll_start == text.end()) {
        scroll_start = text.begin();
    }
}    

            