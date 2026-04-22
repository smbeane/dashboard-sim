# LED Dashboard Simulator

## Command Line Arguments
`--page` page selection if there is a specific page to be ran (no default)

`--font_size` vertical font size (3 x 5)

`--refresh_rate` the refresh rate of the simulator (defaults to 60 fps)

`--window_width, --window_height` dimensions for the simulation window (defaults to 1280 x 640)


## Folder Structure
``` 
dashboard_sim
├── build
├── fonts
|   ├── CMakeLists.txt
|   └── headers
|       └── fonts.hpp    
├── color
|   ├── CMakseLists.txt
|   ├── src
|   |   └── color.cpp
|   └── headers
|       └── color.hpp
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
|   └── test
|       ├── src
|       |   └── test.cpp
|       └── headers
|           └── test.hpp
└── components 
    ├── CMakeLists.txt
    ├── textbox
    |   ├── src
    |   |   └── textbox.cpp
    |   ├── headers
    |   |   └── textbox.hpp
    └── line
        ├── src
        |   └── line.cpp
        └── headers
            └── line.hpp
```
