cmake_minimum_required(VERSION 3.16)
project(dashboard_sim LANGUAGES CXX VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")

add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(color)
add_subdirectory(simulator)
add_subdirectory(fonts)
add_subdirectory(components)

add_executable(dashboard_sim hello.cpp)

target_link_libraries(dashboard_sim PRIVATE color simulator fonts components SDL3::SDL3)
