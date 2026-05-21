#ifndef INPUT_HPP
#define INPUT_HPP

#include <array>
#include <functional>
#include <optional>

#include <pages/actions.hpp>

template <size_t N>
class InputHandler {
    public:
        std::array<std::function<PageActionResult()>, N> actions;

        /**
         * @brief Stores a callback for a named input action.
         *
         * @param action The action index to bind.
         * @param func   The callback invoked when the action occurs.
         */
        void bind(size_t action, std::function<PageActionResult()> func) {
            if (action < N) actions[action] = func;
        }

        /**
         * @brief Executes the bound callback for a given action.
         *
         * @param action The action index to invoke.
         * @return The optional integer result from the callback.
         */
        PageActionResult execute(size_t action) const {
            if (action < N && actions[action]) return actions[action]();

            return {};
        }
};

#endif // INPUT_HPP
