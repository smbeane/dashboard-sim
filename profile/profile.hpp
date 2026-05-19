#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>

#include <color/colors.hpp>

class Profile {
    private:
        std::string username;
        Color primary;
        Color secondary;
        Color accent;

    public: 
        Profile() { init_profile(); };

        void init_profile();

        nlohmann::json parse_value(std::string value);

        void parse_profile(std::string filename);

        Color get_primary() const { return primary; };

        Color get_secondary() const {return secondary; };

        Color get_accent() const { return accent; };

        Color set_primary(Color& new_primary);

        Color set_secondary(Color& new_secondary);

        Color set_accent(Color& new_accent);

};

#endif // PROFILE_HPP