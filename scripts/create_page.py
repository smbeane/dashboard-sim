import os
import argparse
import textwrap


def create_page(name, subdir):
    page_name = name[0].upper() + name[1:] + 'Page'
    base_path = os.path.join(subdir, name.lower())
    os.makedirs(base_path, exist_ok=True)

    include_guard = f"{name.upper()}_HPP"

    header_content = textwrap.dedent(f'''
#ifndef {include_guard}
#define {include_guard}

#include "../page.hpp"

class {page_name} : public Page {{
public:
    {page_name}() : Page("{page_name}") {{}}

    {page_name}(std::string name) : Page(name) {{}}

    void init_page() override;
    void update_data() override;
    void execute_action(RotaryAction action, int rotary) override;
}};

#endif // {include_guard}
''')

    source_content = textwrap.dedent(f'''
#include "{name.lower()}.hpp"

void {page_name}::init_page() {{
    // TODO: initialize components for {page_name}
}}

void {page_name}::update_data() {{
    // TODO: update page state
}}

void {page_name}::execute_action(RotaryAction action, int rotary) {{
    // TODO: handle page input actions
}}
''')

    with open(os.path.join(base_path, f"{name.lower()}.hpp"), "w") as f:
        f.write(header_content)

    with open(os.path.join(base_path, f"{name.lower()}.cpp"), "w") as f:
        f.write(source_content)


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Page boilerplate generator")
    parser.add_argument("-n", "--name", required=True, help="Name of the page")
    parser.add_argument("-s", "--subdir", default="pages", help="Target directory for the page")
    args = parser.parse_args()

    print(f"Creating page: {args.name} in {args.subdir}")
    create_page(args.name, args.subdir)
