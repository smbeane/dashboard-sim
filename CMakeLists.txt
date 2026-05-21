cmake_minimum_required(VERSION 3.16)
project(dashboard_sim LANGUAGES CXX VERSION 1.0.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

find_package(nlohmann_json REQUIRED)

# include(FetchContent)
# FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
# FetchContent_MakeAvailable(json)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIGURATION>")



add_subdirectory(SDL EXCLUDE_FROM_ALL)
add_subdirectory(color)
add_subdirectory(simulator)
add_subdirectory(fonts)
add_subdirectory(components)
add_subdirectory(pages)
add_subdirectory(utils)
add_subdirectory(point)
add_subdirectory(profile)

add_executable(dashboard_sim main.cpp)

target_link_libraries(dashboard_sim PRIVATE simulator pages SDL3::SDL3 nlohmann_json::nlohmann_json profile)
