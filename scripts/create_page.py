import os
import argparse

def create_page(name, subdir):
    page_name = name[0].upper() + name[1:] + "Page"
    base_path = f"{subdir}/{name.lower()}"
    os.makedirs(base_path, exist_ok=True)

    with open(f"{base_path}/{name.lower()}.hpp", "w") as f:
        f.write(f'''#ifndef {name.upper()}_HPP
#define {name.upper()}_HPP

#include "../page.hpp"

class {page_name} : public Page {{
    public: 
        // TODO: define page specific variables
        // TODO: add variables to each constructor    
        
        /**
         * @brief 
         */
        {page_name}() : Page("") {{}}

        /**
         * @brief 
         */
        {page_name}(std::string name) : Page(name)  {{}}

        /**
         * @brief
         */
        void init_page() override;

        /**
         * @brief
         */
        void update_data() override;

        // TODO: define page specific functions
}};

#endif // {page_name}_HPP
''')
        
    # Write Source File
    with open(f"{base_path}/{name.lower()}.cpp", "w") as f:
        f.write(f'''#include "{name.lower()}.hpp"

void {page_name}::init_page() {{

}}

void {page_name}::update_data() {{

}}  
''')

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Professional Component Boilerplate Generator")
    
    parser.add_argument("-n", "--name", required=True, help="Name of the page")
    parser.add_argument("-s", "--subdir", default="pages", help="Target directory for the component")

    args = parser.parse_args()

    print(f"Creating page: {args.name} in {args.subdir}")
    create_page(args.name, args.subdir)