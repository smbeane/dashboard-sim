#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color/colors.hpp>
#include <point/point.hpp>
#include <array>

inline constexpr int MATRIX_WIDTH = 64;
inline constexpr int MATRIX_HEIGHT = 32;
inline constexpr size_t MATRIX_SIZE = MATRIX_WIDTH * MATRIX_HEIGHT;

inline bool matrix_in_bounds(int x, int y) {
    return x >= 0 && x < MATRIX_WIDTH && y >= 0 && y < MATRIX_HEIGHT;
}

inline size_t matrix_index(int x, int y) {
    return static_cast<size_t>(y) * MATRIX_WIDTH + static_cast<size_t>(x);
}

class Component {
    // TODO: add center on page function with left or right bias
    // TODO: implement bounds checking on all components
    protected: 
        Color primary;
        Color secondary;
        bool is_visible;

    public:

        Component (Color p, Color s) 
        : primary(p), secondary(s), is_visible(false) {}

        void show_component() { is_visible = true;  }
        void hide_component() { is_visible = false; }

        virtual void render_component(std::array<Color, MATRIX_SIZE>& matrix) = 0;

        void change_color (const Color& new_color) { primary = secondary = new_color; };

        void change_primary (const Color& new_primary) { primary = new_primary; };

        void change_secondary (const Color& new_secondary) { secondary = new_secondary; };

};

#endif // COMPONENT_HPP