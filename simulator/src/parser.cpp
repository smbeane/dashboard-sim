#include "../headers/parser.hpp"
#include <iostream>
#include <stdexcept>

std::vector<std::string> flags = {"--page", "--font_size", "--refresh_rate", "--window_width", "--window_height"};

std::vector<int> parse_args (int argc, char* args[]) {
    std::vector<int> inputs(5, 0);
    inputs[3] = 1408;
    inputs[4] = 704;
    
    for (int i = 0; i < argc; i++) {
        std::string flag(args[i]);
        
        if (!(i + 1 < argc)) continue; 
        std::string value(args[i + 1]);
        for (int j = 0; j < static_cast<int>(flags.size()); j++) {
            if (flag == flags[j]) {
                try {
                    inputs[j] = std::stoi(value);
                } catch (const std::invalid_argument&) {
                    std::cerr << "Warning: invalid value for " << flag << ": " << value << ", using default\n";
                } catch (const std::out_of_range&) {
                    std::cerr << "Warning: out-of-range value for " << flag << ": " << value << ", using default\n";
                }
            }
        }
    }

    return inputs;

}