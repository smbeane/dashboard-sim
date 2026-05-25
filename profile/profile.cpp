#include "profile.hpp"
#include "defaults.hpp"


void Profile::init_profile(std::string p) {
    if (p == "") this->path = std::string(PROJECT_ROOT_DIR) + "/profile/profile.json";
    else this->path = "../profile/profile.json";

    std::ifstream file(this->path);
    if (file) {
        nlohmann::json data = nlohmann::json::parse(file);

        username = data["username"];
        primary = data["primary"];
        secondary = data["secondary"];
        accent = data["accent"];


    } else {
        username = DEFAULT_USERNAME;
        primary = DEFAULT_PRIMARY;
        secondary = DEFAULT_SECONDARY;
        accent = DEFAULT_ACCENT;
    }

}

nlohmann::json Profile::parse_value(std::string value) {
    std::ifstream file(this->path);

    if (file) {
        nlohmann::json data = nlohmann::json::parse(file);
        
        return data[value];

    } else {
        return {};
    }
}

Color Profile::set_primary(const Color& new_primary) {
    primary = new_primary;

    return primary;
}

Color Profile::set_secondary(const Color& new_secondary) {
    secondary = new_secondary;

    return secondary;
}

Color Profile::set_accent(const Color& new_accent) {
    accent = new_accent;

    return accent;
}

void Profile::save_profile() {
    nlohmann::json data; 

    data["username"] = this->username;
    data["primary"] = this->primary;
    data["secondary"] = this->secondary;
    data["accent"] = this->accent;

    std::ofstream file(path);
    if (file) {
        file << data.dump(4);
    }
}