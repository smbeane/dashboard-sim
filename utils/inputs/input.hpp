#ifndef INPUT_HPP
#define INPUT_HPP

#include <array>
#include <functional>
#include <optional>

template <size_t N>
class InputHandler {
    public:
        std::array<std::function<std::optional<int>()>, N> actions;

        void bind(size_t action, std::function<std::optional<int>()> func) {
            if (action < N) actions[action] = func;
        }

        std::optional<int> execute(size_t action) const {
            if (action < N && actions[action]) return actions[action]();

            return {};
        }
};

#endif // INPUT_HPP
