#include "../headers/parser.hpp"

std::vector<std::string> flags = {"--page", "--font_size", "--refresh_rate", "--window_width", "--window_height"};

std::vector<int> parse_args (int argc, char* args[]) {
    std::vector<int> inputs(5, 0);
    inputs[3] = 1408;
    inputs[4] = 704;
    
    for (int i = 0; i < argc; i++) {
        std::string flag(args[i]);
        
        if (!(i + 1 < argc)) continue; 
        std::string value(args[i + 1]);
        for (int j = 0; j < flags.size(); j++) {
            if ( flag == flags[j] ) inputs[j] = std::stoi(value);
        } 
    }

    return inputs;

}