#ifndef TIME_PAGE_HPP
#define TIME_PAGE_HPP

#include <string>
#include <array>
#include <functional>
#include <optional>

#include <utils/time/time.hpp>
#include <utils/inputs/rotary_encoder.hpp>
#include <components/components.hpp>
#include "page_components/clock.hpp"
#include "../page.hpp"

class TimePage : public Page {
    private:
        std::string time;
        std::string date;
        std::string year;

        TextBox *time_tb = nullptr;
        TextBox *date_tb = nullptr;
        TextBox *year_tb = nullptr;
        Clock   *clock   = nullptr;
    
    public:

        RotaryEncoder rotary;

        TimePage(std::string name) : Page(name), time(""), rotary() { init_page(); };

        TimePage(std::string name, Profile p) : Page(name, p), time(""), rotary() { init_page(); };
        
        /**
         * @brief Builds the clock and text components for the time page.
         */
        void init_page();
        
        /**
         * @brief Updates the displayed time, date, and year each frame.
         */
        void update_data();

};



#endif // TIME_PAGE_HPP