add_library(time_components STATIC clock.cpp)

target_include_directories(time_components PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(time_components PRIVATE components)