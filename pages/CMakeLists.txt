add_library(
    pages
    font_test/font_test.hpp
    font_test/font_test.cpp
)


target_link_libraries(components PUBLIC color)
target_include_directories(pages PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/font_test")
target_compile_definitions(pages PUBLIC PAGES_VERSION=1.0)

