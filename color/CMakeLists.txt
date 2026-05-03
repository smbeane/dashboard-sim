add_library (
    color
    headers/color.hpp src/color.cpp
    headers/defaults.hpp
)

target_link_libraries ( color PUBLIC SDL3::SDL3 )
target_include_directories ( color INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions ( color PUBLIC COLOR_VERSION=1.0)