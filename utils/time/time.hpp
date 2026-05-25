#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <string>

/**
 * @brief Returns the current local time formatted as a short string.
 *
 * @return Time string in hh:mm AM/PM format.
 */
std::string get_time_str();

/**
 * @brief Returns the current local abbreviated date string.
 *
 * @return Date string in the format "Day MonDD".
 */
std::string get_date_str();

/**
 * @brief Returns the current local year as a string.
 *
 * @return Four-digit year string.
 */
std::string get_year_str();


#endif // TIME_HPP