add_subdirectory(time/page_components)

add_library(pages STATIC
    page.cpp page.hpp
    component_demo/component_demo.cpp component_demo/component_demo.hpp
    time/timepage.cpp time/timepage.hpp
    colorpicker/colorpicker.cpp colorpicker/colorpicker.hpp
    pageselection/pageselection.cpp pageselection/pageselection.hpp
)

target_include_directories(pages PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

target_link_libraries(pages 
    PUBLIC 
        components 
        color 
        profile
    PRIVATE    
        utils 
        time_components
)

