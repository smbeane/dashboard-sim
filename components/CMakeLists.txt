add_library(components STATIC
    component.hpp
    components.hpp
    rectangle/rectangle.cpp rectangle/rectangle.hpp
    line/line.cpp line/line.hpp
    circle/circle.cpp circle/circle.hpp
    progress_bar/progress_bar.cpp progress_bar/progress_bar.hpp
    slider/slider.cpp slider/slider.hpp
    textbox/textbox.cpp textbox/textbox.hpp

)

target_include_directories(components PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

target_link_libraries(components PUBLIC color fonts)

target_compile_definitions(components PUBLIC COMPONENTS_VERSION=1.0)