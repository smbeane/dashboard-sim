# LED Dashboard Simulator

## Directions (Starting in base directory)
1. `cd build`
2. `cmake .. --preset {PRESET}`
3. `ninja {ARGS}`

### Command Line Arguments
`--page` page selection if there is a specific page to be ran (no default)

`--font_size` vertical font size (3 x 5)

`--refresh_rate` the refresh rate of the simulator (defaults to 60 fps)

`--window_width, --window_height` dimensions for the simulation window (defaults to 1280 x 640)


# Contributing

## Folder Structure
``` 
dashboard_sim
├── build
├── fonts
├── color
├── SDL...
├── pages
|   ├── CMakeLists.txt
|   ├── spotify
|   |   ├── src
|   |   |   └── spotify.cpp
|   |       ├── spotifyClass.cpp
|   |   ├── headers
|   |   |   └── spotify.hpp
|   |       └── spotifyClass.hpp
|   |   └── helpers
|   ├── ...
|
└── components 
    ├── CMakeLists.txt
    ├── textbox
    |   └── textbox.cpp
    |   └── textbox.hpp
    ├── ...

```

## Helpful Scripts

### Creating Components and Pages

To create a component or page, use the `create_component.py` or `create_page.py` scripts with the respective name as a command line argument. As of 4/29/2026, you will have to manually add to the `CMakeLists.txt` and rebuild, however, there are plans to improve the scripts down the line. 
