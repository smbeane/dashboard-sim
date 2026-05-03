add_library(
    pages
    page.hpp page.cpp
    component_demo/component_demo.cpp component_demo/component_demo.hpp
    time/timepage.cpp time/timepage.hpp
)


target_link_libraries(pages PUBLIC color components utils)
target_include_directories(pages PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

