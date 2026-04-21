add_library (
    simulator
    headers/renderer.hpp
    src/renderer.cpp
)

target_link_libraries ( simulator PUBLIC color SDL3::SDL3 )
target_include_directories ( simulator PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")
target_compile_definitions ( simulator PUBLIC COLOR_VERSION=1.0)