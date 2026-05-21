#include <renderer.hpp>

bool Renderer::able_to_render() {
    return sdl_init_success;
}

bool Renderer::init_window() {

    if (SDL_Init( SDL_INIT_VIDEO ) == false ) {
    
        SDL_Log ( "SDL could not initalize!: SDL error: %s\n", SDL_GetError() );
        return false;
    
    }

    if (window = SDL_CreateWindow( window_name.c_str(), window_width, window_height, 0 ); window == nullptr ) {
    
        SDL_Log( "Window could not be created, SDL error: %s\n", SDL_GetError() );
        return false;
    
    } else {
        
        renderer = SDL_CreateRenderer( window , NULL);
        
        return true;
    
    }
}

bool Renderer::render_matrix(std::array<Color, MATRIX_SIZE> matrix) {

    SDL_SetRenderDrawColor( renderer, 10, 10, 10, 255 );
    SDL_RenderClear( renderer );

    for (int i = 0; i < 64; i++) {
        for (int j = 0; j < 32; j++) {
            SDL_Color color = matrix[j * 64 + i].getSDL_Color();
            SDL_SetRenderDrawColor( renderer, color.r, color.g, color.b, color.a);

            SDL_FRect pixel;
            pixel.x = (pixel_gap * (i * 2 + 1) + (pixel_width * i));
            pixel.y = (pixel_gap * (j * 2 + 1) + (pixel_height * j));
            pixel.w = pixel_width;
            pixel.h = pixel_height;
            

            SDL_RenderFillRect( renderer, &pixel);
        }
    }

    SDL_RenderPresent( renderer );

    return true;

}

void Renderer::close_window() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow( window );
    window = nullptr;

    SDL_Quit();
}



