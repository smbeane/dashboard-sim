add_library (
    color
    headers/color.hpp
    src/color.cpp
)

target_link_libraries ( color PUBLIC SDL3::SDL3 )
target_include_directories ( color PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_compile_definitions ( color PUBLIC COLOR_VERSION=1.0)