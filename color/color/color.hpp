#ifndef COLOR_HPP
#define COLOR_HPP

#include <cstdint>
<<<<<<< HEAD
#include <string>
#include <SDL3/SDL_pixels.h>
=======
>>>>>>> d28efb2 (save work)
#include <iostream>
#include <nlohmann/json.hpp>

#include <SDL3/SDL_pixels.h>

class Color {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;
        bool is_visible;

        /**
         * @brief Constructs black color
        */
        constexpr Color() : r(0), g(0), b(0), is_visible(true) {};

        /**
         * @brief Constructs a color of defined RGB 
         * 
         * @param r 8-bit red value of Color (0-255)
         * @param g 8-bit green value of Color (0-255)
         * @param b 8-bit blue value of Color (0-255)
         */
        constexpr Color(uint8_t r, uint8_t g, uint8_t b) : r(r), g(g), b(b), is_visible(true) {};

        /**
         * @brief Constructs a Color of defined RGB and transparency
         * 
         * @param r 8-b red value of Color (0-255)
         * @param g 8-bit green value of Color (0-255)
         * @param b 8-bit blue value of Color (0-255)
         * @param v Sets visibility of color (0 for transparent, 1 for visible)
         */
        constexpr Color(uint8_t r, uint8_t g, uint8_t b, bool v) 
            : r(r), g(g), b(b), is_visible(v) {
        }   

        /**
         * @brief Gets the corresponding SDL_Color
         * 
         * @return SDL_Color corresponding to the color
         */
        SDL_Color getSDL_Color ();

        /**
         * @brief Checks if color is visible
         * 
         * @returns bool if visible
         */
        bool is_transparent() const { return !is_visible; }

        friend std::ostream& operator<<(std::ostream& os, const Color& color);



};

inline void to_json(nlohmann::json& j, const Color& c) {
    j = {c.r, c.g, c.b};
}

inline void from_json(const nlohmann::json& j, Color& c) {
    c.r = j.at(0).get<uint8_t>();
    c.g = j.at(1).get<uint8_t>();
    c.b = j.at(2).get<uint8_t>();
    c.is_visible = true;
}

#endif // COLOR_HPP