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
    public: 
        // TODO: define component specific variables
        // TODO: add variables to each constructor    
        
        /**
         * @brief default constructor, initializes to (0, 0) and completely transparent
         */
        {class_name}() : Component(0, 0, transparent, transparent) {{}}

        /**
         * @brief basic {class_name} constructor
         *
         * @param x, y ______ coordinates of {class_name}
         * @param border, infill defined colors of {class_name}
         */
        {class_name} (int x, int y, Color border, Color infill) 
        :  Component(x, y, border, infill)  {{}}

        /**
         * @brief renders all defined components in constructor
         *
         * @param matrix reference to array of pixels
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