#ifndef DEFAULT_COLORS_HPP
#define DEFAULT_COLORS_HPP

#include "../color/color.hpp"

inline constexpr Color BLACK(0, 0, 0, true);
inline constexpr Color WHITE(255, 255, 255, true);
inline constexpr Color GREY(128, 128, 128, true);
inline constexpr Color PROFILE_COLOR(63, 81, 181, true);
inline constexpr Color UNSELECTED(80, 80, 80, true);
inline constexpr Color TRANSPARENT(0, 0, 0, false);

#endif // DEFAULT_COLORS_HPP