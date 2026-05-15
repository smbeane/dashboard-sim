add_library (utils STATIC
    time/time.cpp time/time.hpp
    inputs/rotary_encoder.hpp
    inputs/input.hpp
)

target_include_directories( utils PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
)