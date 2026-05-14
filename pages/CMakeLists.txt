add_subdirectory(time/page_components)

add_library(pages STATIC
    page.cpp page.hpp
    component_demo/component_demo.cpp component_demo/component_demo.hpp
    time/timepage.cpp time/timepage.hpp
)

target_include_directories(pages PUBLIC 
    "${CMAKE_CURRENT_SOURCE_DIR}/.."
)

target_link_libraries(pages 
    PUBLIC 
        components 
        color 
    PRIVATE    
        utils 
        time_components
)

