#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <cmath>

#include "../component.hpp"
#include "../line/line.hpp"


class Slider : public Component {
    private:

        int length;
        int min; 
        int max;
        int progress;
        bool wrap;
    
    public: 
        
        /**
         * @brief Constructs default Slider, position (0, 0) 
         *        completely transparent with 0 length and progress
         */
        Slider() : Component(0, 0, TRANSPARENT, TRANSPARENT), 
                   length(0), min(0), max(0), progress(0), wrap(false) {}

        /**
         * @brief Constructs a Slider at defined pixel location with given
         *        length and current progress
         * 
         * @param x The left pixel offset from left edge of screen (0-63)
         * @param y The vertical offset from the top edge of screen (0-31)
         * @param length The pixel length of the bar
         * @param min The minimum progress level
         * @param max The maximum progress level
         * @param progress The current progress level (min-max)
         * @param wrap True if progress should wrap from max to min on increment, or false otherwise
         * @param primary The Color of the bar itself
         * @param secondary The Color of the progress indicator
         *  
         */
        Slider(int x, int y, int length , int min, int max, int progress, bool wrap, Color primary, Color secondary ) 
        :  Component( x, y, primary, secondary ), length(length), min(min), max(max), progress( progress ), wrap(wrap)  {}

        /**
         * @brief Renders component by first rendering the bar as a Line,
         *        and then rendering the progress indicator over top
         * 
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;

        /**
         * @brief Returns the current progress 
         * 
         * @return progress variable
         */
        int get_progress() { return progress; }

        /**
         * @brief Updates the progress, but doesn't rerender component
         * 
         * @param new_progress The percentage (0-100) of the way through the progress bar
         */
        void set_progress(int new_progress);

        /**
         * @brief Increments progress value by 1 until reaching the maximum
         */
        void increment_slider() {
            if (progress < max) {
                progress += 1;
            } else if (wrap) {
                progress = min;
            }
        };

        /**
         * @brief Decrements progress value by 1 until reaching minimum
         *        or wrapping around to maximum
         */
        void decrement_slider() {
            if (progress > min) {
                progress -= 1;
            } else if (wrap) {
                progress = max;
            }
        }
};

#endif // SLIDER_HPP
                