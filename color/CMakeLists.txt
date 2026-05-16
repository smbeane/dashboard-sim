add_library (color STATIC
    colors.hpp
    color/color.hpp color/color.cpp
    defaults/defaults.hpp
)

target_link_libraries ( color PUBLIC SDL3::SDL3 )
target_include_directories ( color INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/..")
target_compile_definitions ( color PUBLIC COLOR_VERSION=1.0)