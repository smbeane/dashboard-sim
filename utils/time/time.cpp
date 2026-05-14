#include "time.hpp"

#include <format>

std::string get_time_str() {
    
    auto now = std::chrono::system_clock::now();
    std::chrono::zoned_time local{std::chrono::current_zone(), now};

    std::string s = std::format("{:%I:%M %p}", local);
    s.erase(8);

    return s;

}

std::string get_date_str() {

    auto now = std::chrono::system_clock::now();
    std::chrono::zoned_time local{std::chrono::current_zone(), now};

    std::string s = std::format("{:%a %b%d}", local);

    return s;
}

std::string get_year_str() {

    auto now = std::chrono::system_clock::now();
    std::chrono::zoned_time local{std::chrono::current_zone(), now};

    std::string s = std::format("{:%Y}", local);
    
    return s;
}