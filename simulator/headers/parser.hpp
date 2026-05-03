#ifndef PARSER_HPP
#define PARSER_HPP

#include <vector>
#include <string>

extern std::vector<std::string> flags;

std::vector<int> parse_args (int argc, char* args[]);


#endif // PARSER_HPP