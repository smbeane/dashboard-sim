#ifndef TIME_PAGE_HPP
#define TIME_PAGE_HPP

#include <string>
#include <array>
#include <functional>

#include <utils/time/time.hpp>
#include <utils/inputs/rotary_encoder.hpp>
#include <components/components.hpp>
#include "page_components/clock.hpp"
#include "../page.hpp"

class TimePage : public Page {
    public:
        std::string time;
        std::string date;
        std::string year;

        RotaryEncoder rotary;

        TimePage(std::string name) : Page(name), time(""), clock(nullptr), rotary() { init_page(); };
        
        void init_page();
        
        void update_data();

        private: 
            TextBox *time_tb = nullptr;
            TextBox *date_tb = nullptr;
            TextBox *year_tb = nullptr;
            Clock   *clock   = nullptr;
};



#endif // TIME_PAGE_HPP