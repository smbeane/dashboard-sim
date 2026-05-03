add_library (
    utils
    headers/time.hpp src/time.cpp
)

target_include_directories( utils PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/headers")