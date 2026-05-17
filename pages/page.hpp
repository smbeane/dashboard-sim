#ifndef PAGE_HPP
#define PAGE_HPP

#include <vector>
#include <string>
#include <array>
#include <memory>

#include <color/colors.hpp>
#include <components/component.hpp>
#include <utils/inputs/rotary_encoder.hpp>

class Page {
    // TODO: implement framerate
    // TODO: add_component function that returns a pointer reference
    // TODO: figre out how to implement multiple action types
    protected: 
        std::vector<std::unique_ptr<Component>> components;

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

    
    public:
        std::string name;

        Page() : name("Basic Page") {};

        Page(std::string name) : name(name) {};

        virtual void init_page () = 0;
        
        virtual void update_data() = 0;
        
        virtual void render_page(std::array<Color, MATRIX_SIZE>& matrix);

        virtual void execute_action(RotaryAction action, int rotary);
};


#endif // PAGE_HPP