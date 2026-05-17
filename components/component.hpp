#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color/colors.hpp>
#include <point/point.hpp>
#include <array>

inline const size_t MATRIX_SIZE = 2048;

class Component {
    // TODO: add center on page function with left or right bias
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