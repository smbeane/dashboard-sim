import os
import sys

def create_component(name):
    class_name = name[0].upper() + name[1:]
    base_path = f"../components/{name.lower()}"
    os.makedirs(base_path, exist_ok=True)

    with open(f"{base_path}/{name.lower()}.hpp", "w") as f:
        f.write(f'''#ifndef {name.upper()}_HPP
#define {name.upper()}_HPP

#include "../component.hpp"

class {class_name} : public Component {{
    public: 
        
        // define additional variables and add to constructor

        {class_name} (int x, int y, Color border, Color infill) 
        :  Component(x, y, border, infill)  {{}}

        void render_component(std::array<Color, 64*32>& matrix) override;

        // define component specific functions
}};

#endif // {name.upper()}_HPP
                ''')
        
        with open(f"{base_path}/{name.lower()}.cpp", "w") as f:
            f.write(f'''#include <{name.lower()}.hpp>

void {class_name}::render_component(std::array<Color, 64*32>& matrix) {{

}}

            ''')

if len(sys.argv) > 1:
    component_name = sys.argv[1]
    print(f"Creating component: {component_name}")
    create_component(component_name)
else: 
    print("Error: no name provided")