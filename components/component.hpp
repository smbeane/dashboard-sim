#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <color/colors.hpp>
#include <point/point.hpp>
#include <array>

inline constexpr int MATRIX_WIDTH = 64;
inline constexpr int MATRIX_HEIGHT = 32;
inline constexpr size_t MATRIX_SIZE = MATRIX_WIDTH * MATRIX_HEIGHT;

/**
 * @brief Checks whether a pixel coordinate is inside the LED matrix bounds.
 *
 * @param x X coordinate to validate.
 * @param y Y coordinate to validate.
 * @return true when the point is inside [0,64)x[0,32), false otherwise.
 */
inline bool matrix_in_bounds(int x, int y) {
    return x >= 0 && x < MATRIX_WIDTH && y >= 0 && y < MATRIX_HEIGHT;
}

/**
 * @brief Converts 2D matrix coordinates into a flattened linear buffer index.
 *
 * @param x X coordinate of the pixel.
 * @param y Y coordinate of the pixel.
 * @return Linear index into a MATRIX_SIZE array.
 */
inline size_t matrix_index(int x, int y) {
    return static_cast<size_t>(y) * MATRIX_WIDTH + static_cast<size_t>(x);
}

/**
 * @brief Base class for all drawable components in the LED matrix.
 */
class Component {
    // TODO: add center on page function with left or right bias
    protected: 
        Color primary;
        Color secondary;
        bool is_visible;

    public:

        Component (Color p, Color s) 
        : primary(p), secondary(s), is_visible(false) {}

        /**
         * @brief Marks this component as visible for rendering.
         */
        void show_component() { is_visible = true;  }

        /**
         * @brief Hides this component so it is skipped during rendering.
         */
        void hide_component() { is_visible = false; }

        /**
         * @brief Renders the component into the LED matrix pixel buffer.
         *
         * @param matrix The target display buffer to draw into.
         */
        virtual void render_component(std::array<Color, MATRIX_SIZE>& matrix) = 0;

        /**
         * @brief Updates both primary and secondary colors to the same value.
         *
         * @param new_color The new color to use for the component.
         */
        void change_color (const Color& new_color) { primary = secondary = new_color; };

        /**
         * @brief Updates the primary color used by this component.
         *
         * @param new_primary The new primary color.
         */
        void change_primary (const Color& new_primary) { primary = new_primary; };

        /**
         * @brief Updates the secondary color used by this component.
         *
         * @param new_secondary The new secondary color.
         */
        void change_secondary (const Color& new_secondary) { secondary = new_secondary; };

};

#endif // COMPONENT_HPP