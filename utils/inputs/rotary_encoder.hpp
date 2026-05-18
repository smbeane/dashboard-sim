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

/**
 * @brief A rotary encoder input handler with predefined left/right/press actions.
 */
class RotaryEncoder : public InputHandler<static_cast<size_t>(RotaryAction::COUNT)> {
    public:
        /**
         * @brief Binds a callback to a rotary action.
         *
         * @param action Rotary action to bind.
         * @param func   Callback invoked when the action occurs.
         */
        void bind(RotaryAction action, std::function<std::optional<int>()> func) {
            InputHandler::bind(static_cast<size_t>(action), std::move(func));
        }

        /**
         * @brief Executes the callback bound to the requested rotary action.
         *
         * @param action The action to execute.
         * @return Optional integer result from the bound callback.
         */
        std::optional<int> execute (RotaryAction action) const {
            return InputHandler::execute(static_cast<size_t>(action));
        }
};

#endif // INPUT_TYPES_HPP