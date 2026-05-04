add_library(
    pages
    page.cpp
    component_demo/component_demo.cpp
    time/timepage.cpp
)

add_subdirectory(time/components)
target_link_libraries(pages PRIVATE time_components)

target_link_libraries(pages PUBLIC color components utils )
target_include_directories(pages PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

