#include "graphics.h"
//#include <resources.h>

const int Graphics::WIDTH = 640, Graphics::HEIGHT = 480;

bool Graphics::init_sdl()
{
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
    {
        printf("Error: Failed to init SDL2: %s\n", 
                SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
            "Balloonacy",               //title
            SDL_WINDOWPOS_UNDEFINED,    //init x pos
            SDL_WINDOWPOS_UNDEFINED,    //init y pos
            WIDTH,                      
            HEIGHT,
            SDL_WINDOW_OPENGL           //window usable with OpenGL
    );

    if( window == NULL )
    {
        printf("Error: Failed to create window: %s\n", 
                SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer( 
            window, 
            -1, 
            SDL_RENDERER_ACCELERATED | 
            SDL_RENDERER_PRESENTVSYNC
    );

    if( !( IMG_Init( IMG_INIT_PNG ) & IMG_INIT_PNG ) )
    {
        printf("Error: Failed to init image loading: %s\n", 
                SDL_GetError());
        return false;
    }

    if( TTF_Init() == -1 )
    {
        printf("Error: Failed to init TTF loading: %s\n", 
                SDL_GetError());
        return false;
    }

    return true;
}

Graphics::Graphics()
{
    init_sdl();
}

void Graphics::clear_screen()
{
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
}

void Graphics::present_renderer()
{
    SDL_RenderPresent( renderer );
}

int Graphics::get_width()
{
    return WIDTH;
}

int Graphics::get_height()
{
    return HEIGHT;
}

Graphics::~Graphics()
{
    SDL_DestroyWindow( window );
    SDL_DestroyRenderer( renderer );
    IMG_Quit();
    SDL_Quit();
    printf("Shut down SDL.\n");
}
