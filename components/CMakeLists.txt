add_library(
    components
    line/line.cpp line/line.hpp
    rectangle/rectangle.cpp rectangle/rectangle.hpp

)

target_link_libraries(components PUBLIC color)
target_include_directories(components PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/line" "${CMAKE_CURRENT_SOURCE_DIR}/rectangle")
target_compile_definitions(components PUBLIC COMPONENTS_VERSION=1.0)