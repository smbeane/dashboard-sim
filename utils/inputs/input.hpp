#ifndef INPUT_HPP
#define INPUT_HPP

#include <array>
#include <functional>

template <size_t N>
class InputHandler {
    public:
        std::array<std::function<void()>, N> actions;

        void bind(size_t action, std::function<void()> func) {
            if (action < N) actions[action] = func;
        }

        void execute(size_t action) const {
            if (action < N && actions[action]) actions[action]();
        }
};

#endif // INPUT_HPP
