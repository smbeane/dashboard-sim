#ifndef PROFILE_HPP
#define PROFILE_HPP

#include <string>
#include <fstream>
#include <vector>

#include <nlohmann/json.hpp>
#include <color/colors.hpp>

class Profile {
    private:
        std::string path;
        std::string username;
        Color primary;
        Color secondary;
        Color accent;

    public: 
        Profile() { init_profile(""); };

        Profile(std::string p) { init_profile(p); };

        void init_profile(std::string path);

        nlohmann::json parse_value(std::string value);

<<<<<<< HEAD
        void save_profile();

=======
>>>>>>> d28efb2 (save work)
        Color get_primary() const { return primary; };

        Color get_secondary() const {return secondary; };

        Color get_accent() const { return accent; };

        Color set_primary(const Color& new_primary);

        Color set_secondary(const Color& new_secondary);

        Color set_accent(const Color& new_accent);

};

#endif // PROFILE_HPP