add_library(profile STATIC
    profile.cpp profile.hpp
    defaults.hpp
)

target_link_libraries(profile PUBLIC color nlohmann_json::nlohmann_json)

target_include_directories(profile PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/..")