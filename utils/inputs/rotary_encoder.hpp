#ifndef INPUT_TYPES_HPP
#define INPUT_TYPES_HPP

#include <array>
#include <functional>

#include "input.hpp"

enum class RotaryAction : size_t {
    Left,
    Right, 
    Press,
    COUNT
};

class RotaryEncoder : public InputHandler<static_cast<size_t>(RotaryAction::COUNT)> {
    public:
        void bind(RotaryAction action, std::function<void()> func) {
            InputHandler::bind(static_cast<size_t>(action), std::move(func));
        }

        void execute (RotaryAction action) const {
            InputHandler::execute(static_cast<size_t>(action));
        }
};

#endif // INPUT_TYPES_HPP