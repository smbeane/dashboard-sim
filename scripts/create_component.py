import os
import argparse

def create_component(name, subdir):
    class_name = name[0].upper() + name[1:]
    # Build path: default to 'components' if no subdir flag is passed
    base_path = f"{subdir}/{name.lower()}"
    os.makedirs(base_path, exist_ok=True)

    # Write Header File
    with open(f"{base_path}/{name.lower()}.hpp", "w") as f:
        f.write(f'''#ifndef {name.upper()}_HPP
#define {name.upper()}_HPP

#include "../component.hpp"

class {class_name} : public Component {{
    private: 
        // TODO: define component specific variables

    public: 
        // TODO: add variables to each constructor  
        // TODO: fill out function comments  
        
        /**
         * @brief Constructs default {class_name}. position (0, 0),
                  completely transparent _____
         */
        {class_name}() : Component(0, 0, TRANSPARENT, TRANSPARENT) {{}}

        /**
         * @brief Constructs a {class_name} at defined _____
         * 
         * @param start_x The horizontal offset from the left edge (0-63)
         * @param start_y The vertical offset from the top edge (0-31)
         * @param primary Color of _____
         * @param border  Color of _____
         */
        {class_name} (int x, int y, Color primary, Color secondary) 
        :  Component(x, y, primary, secondary)  {{}}

        /**
         * @brief Renders component
         *
         * @param matrix A reference to the pixels to be rendered
         */
        void render_component(std::array<Color, 64*32>& matrix) override;

        // TODO: define component specific functions
}};

#endif // {name.upper()}_HPP
''')
        
    # Write Source File
    with open(f"{base_path}/{name.lower()}.cpp", "w") as f:
        f.write(f'''#include "{name.lower()}.hpp"

void {class_name}::render_component(std::array<Color, 64*32>& matrix) {{

}}
''')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Professional Component Boilerplate Generator")
    
    parser.add_argument("-n", "--name", required=True, help="Name of the component")
    parser.add_argument("-s", "--subdir", default="components", help="Target directory for the component")

    args = parser.parse_args()

    print(f"Creating component: {args.name} in {args.subdir}")
    create_component(args.name, args.subdir)