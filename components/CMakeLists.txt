add_library(
    components
    components.hpp
    rectangle/rectangle.cpp rectangle/rectangle.hpp
    line/line.cpp line/line.hpp
    circle/circle.cpp circle/circle.hpp
    progress_bar/progress_bar.cpp progress_bar/progress_bar.hpp

)

target_link_libraries(components PUBLIC color)
target_include_directories(components PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(components PUBLIC COMPONENTS_VERSION=1.0)