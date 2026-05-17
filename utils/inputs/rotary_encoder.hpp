#ifndef INPUT_TYPES_HPP
#define INPUT_TYPES_HPP

#include <array>
#include <functional>
#include <optional>

#include "input.hpp"

enum class RotaryAction : size_t {
    Left,
    Right, 
    Press,
    COUNT
};

class RotaryEncoder : public InputHandler<static_cast<size_t>(RotaryAction::COUNT)> {
    public:
        void bind(RotaryAction action, std::function<std::optional<int>()> func) {
            InputHandler::bind(static_cast<size_t>(action), std::move(func));
        }

        std::optional<int> execute (RotaryAction action) const {
            return InputHandler::execute(static_cast<size_t>(action));
        }
};

#endif // INPUT_TYPES_HPP