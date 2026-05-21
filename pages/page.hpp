#ifndef PAGE_HPP
#define PAGE_HPP

#include <vector>
#include <string>
#include <array>
#include <memory>
#include <optional>

#include <color/colors.hpp>
#include <components/component.hpp>
#include <utils/inputs/rotary_encoder.hpp>
#include <profile/profile.hpp>
#include <pages/actions.hpp>
#include <pages/menu_config.hpp>

class Page {
    // TODO: implement framerate
    // TODO: add_component function that returns a pointer reference
    // TODO: figre out how to implement multiple action types
    protected: 
        std::vector<std::unique_ptr<Component>> components;
        
        Color primary;
        Color secondary;
        Color accent;

        RotaryEncoder rotary_left;

        /**
         * @brief Constructs and adds a component to the page's layout
         * 
         * @tparam T The  class type of the component to create (e.g., TextBox, Slider)
         * @param args... The arguments to forward directly to the component's constructor
         * 
         * @return T* A raw pointer to the newly created component
         */
        template <typename T, typename... Args>
        T* create_component(Args&&... args) {
            auto component = std::make_unique<T>(std::forward<Args>(args)...);
            
            T* component_ptr = component.get();
            components.push_back(std::move(component));

            return component_ptr;
        }

        /**
         * @brief Binds all given actions to their corresponding function
         */
        virtual void bind_actions();

    public:
        std::string name;

        Page() : name("Basic Page"),
            primary(WHITE), secondary(BLACK), accent(GREY) {};

        Page(std::string name) : name(name), 
            primary(WHITE), secondary(BLACK), accent(GREY) {};

        Page(std::string name, Profile p) : name(name), 
            primary(p.get_primary()), secondary(p.get_secondary()), accent(p.get_accent()) {};

        /**
         * @brief Updates any dynamic page state before rendering.
         *
         * Derived pages should override this to refresh text, animations,
         * or other per-frame logic.
         */
        virtual void update_data() = 0;
        
        /**
         * @brief Renders all owned components into the matrix buffer.
         *
         * @param matrix The target display buffer.
         */
        virtual void render_page(std::array<Color, MATRIX_SIZE>& matrix);


        /**
         * @brief Executes an input action for the page.
         *
         * @param action The rotary action to perform.
         * @param rotary Which encoder index triggered the action.
         * @return Optional integer output that may signal page navigation.
         */
        virtual PageActionResult execute_action(RotaryAction action, int rotary);
};


#endif // PAGE_HPP