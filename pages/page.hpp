#ifndef PAGE_HPP
#define PAGE_HPP

#include <vector>
#include <string>
#include <array>
#include <memory>

#include <colors.hpp>
#include <components/component.hpp>

class Page {

    public:
        std::string name;
        std::vector<std::unique_ptr<Component>> components;


        Page () : name("Basic Page"), components() {};

        Page (std::string name) : name(name), components() {};

        virtual void init_page () = 0;
        
        void render_page(std::array<Color, 32*64>& matrix);

        virtual void update_data() = 0;
};


#endif // PAGE_HPP