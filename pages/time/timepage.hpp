#ifndef TIME_PAGE_HPP
#define TIME_PAGE_HPP

#include <string>
#include <array>

#include <time.hpp>
#include "../page.hpp"


class TimePage : public Page {
    public:
        std::string time;
        std::string date;
        std::string year;

        Textbox *time_tb,  *date_tb, *year_tb;
        Line *minute_hand, *hour_hand;

        TimePage(std::string name) : Page(name), time("") { init_page(); };

        void init_page();

        void update_data();
};



#endif // TIME_PAGE_HPP