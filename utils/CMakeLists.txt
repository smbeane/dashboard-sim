add_library (
    utils
    time/time.hpp time/time.cpp
)

target_include_directories( utils PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
)