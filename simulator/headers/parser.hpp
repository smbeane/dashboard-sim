#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

/**
 * @brief Command-line flags recognized by the simulator.
 */
extern std::vector<std::string> flags;

/**
 * @brief Parses simulator command-line arguments into integer values.
 *
 * @param argc Argument count.
 * @param args Argument values.
 * @return Vector containing parsed flag values in the order defined by flags.
 */
std::vector<int> parse_args (int argc, char* args[]);


#endif // PARSER_HPP