add_library(
    pages
    component_demo/component_demo.cpp component_demo/component_demo.hpp
)


target_link_libraries(pages PUBLIC color components)
target_include_directories(pages PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
target_compile_definitions(pages PUBLIC PAGES_VERSION=1.0)

