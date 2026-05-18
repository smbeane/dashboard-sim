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
        RotaryEncoder rotary_left, rotary_right;

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
        
        /**
         * @brief Builds the clock and text components for the time page.
         */
        void init_page();
        
        /**
         * @brief Updates the displayed time, date, and year each frame.
         */
        void update_data();

        /**
         * @brief Binds input actions for the time page.
         */
        void bind_actions();

        /**
         * @brief Executes a rotary action on the time page.
         *
         * @param action The action to handle.
         * @param rotary Which encoder index triggered it.
         * @return Optional output value from the action.
         */
        std::optional<int> execute_action(RotaryAction action, int rotary);

};



#endif // TIME_PAGE_HPP