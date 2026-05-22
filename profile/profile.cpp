#include "profile.hpp"
#include "defaults.hpp"

#include <iostream>

void Profile::init_profile(std::string p) {
    if (p == "") path = std::string(PROJECT_ROOT_DIR) + "/profile/profile.json";
    else path = "../profile/profile.json";
    std::cout << "Path: " << path << std::endl;

    std::ifstream file(path);
    if (file) {
        nlohmann::json data = nlohmann::json::parse(file);

        auto type = data["username"];

        username = data["username"];
        primary = Color(data["primary"][0], data["primary"][1], data["primary"][2]);
        secondary = Color(data["secondary"][0], data["secondary"][1], data["secondary"][2]);
        accent = Color(data["accent"][0], data["accent"][1], data["accent"][2]);

        std::cout << "Profile \"" << username << "\" Found!" << std::endl;

    } else {
        username = DEFAULT_USERNAME;
        primary = DEFAULT_PRIMARY;
        secondary = DEFAULT_SECONDARY;
        accent = DEFAULT_ACCENT;

        std::cout << "No existing profile found" << std::endl;
    }

}

void Profile::parse_profile(std::string filename) {
    std::ifstream file(filename);
    if (file) {
        nlohmann::json data = nlohmann::json::parse(file);
        std::vector<uint8_t> a = data["accent"];

        username = data["username"];
        primary = Color(data["primary"][0], data["primary"][1], data["primary"][2]);
        secondary = Color(data["secondary"][0], data["secondary"][1], data["secondary"][2]);
        accent = Color(data["accent"][0], data["accent"][1], data["accent"][2]);

        std::cout << "Profile \"" << username << "\" Found!" << std::endl;

    } else {

        std::cout << "No existing profile found" << std::endl;

    }
}

nlohmann::json Profile::parse_value(std::string value) {
    std::ifstream file("../profile/profile.json");

    if (file) {
        nlohmann::json data = nlohmann::json::parse(file);
        
        return data[value];

    } else {
        return {};
    }
}

Color Profile::set_primary(Color& new_primary) {
    primary = new_primary;

    return primary;
}

Color Profile::set_secondary(Color& new_secondary) {
    secondary = new_secondary;

    return secondary;
}

Color Profile::set_accent(Color& new_accent) {
    accent = new_accent;

    return accent;
}