import os
import argparse
import textwrap


def create_component(name, subdir):
    class_name = name[0].upper() + name[1:]
    base_path = os.path.join(subdir, name.lower())
    os.makedirs(base_path, exist_ok=True)

    include_guard = f"{name.upper()}_HPP"

    header_content = textwrap.dedent(f'''
#ifndef {include_guard}
#define {include_guard}

#include "../component.hpp"
#include <point/point.hpp>

class {class_name} : public Component {{
private:
    Point pos;

public:
    /**
     * @brief Constructs a default {class_name} at (0,0) with transparent colors.
     */
    {class_name}() : Component(TRANSPARENT, TRANSPARENT), pos({{0, 0}}) {{}}

    /**
     * @brief Constructs a {class_name} at the given position with primary and secondary colors.
     */
    {class_name}(Point position, Color primary, Color secondary)
        : Component(primary, secondary), pos(position) {{}}

    /**
     * @brief Renders the component into the LED matrix buffer.
     */
    void render_component(std::array<Color, MATRIX_SIZE>& matrix) override;
}};

#endif // {include_guard}
''')

    source_content = textwrap.dedent(f'''
#include "{name.lower()}.hpp"

void {class_name}::render_component(std::array<Color, MATRIX_SIZE>& matrix) {{
    // TODO: draw {class_name} into the matrix buffer.
}}
''')

    with open(os.path.join(base_path, f"{name.lower()}.hpp"), "w") as f:
        f.write(header_content)

    with open(os.path.join(base_path, f"{name.lower()}.cpp"), "w") as f:
        f.write(source_content)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Component boilerplate generator")
    parser.add_argument("-n", "--name", required=True, help="Name of the component")
    parser.add_argument("-s", "--subdir", default="components", help="Target directory for the component")
    args = parser.parse_args()

    print(f"Creating component: {args.name} in {args.subdir}")
    create_component(args.name, args.subdir)
