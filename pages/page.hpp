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
    
    public:
        std::string name;

        Page () : name("Basic Page"), components() {};

        Page (std::string name) : name(name), components() {};

        virtual void init_page () = 0;
        
        virtual void update_data() = 0;
        
        virtual void render_page(std::array<Color, 32*64>& matrix);

        virtual void execute_action(RotaryAction action, int rotary);
};


#endif // PAGE_HPP