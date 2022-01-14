#include "game.h"

Game* Game::instance=0;

bool Game::init( const char* title, int x, int y, int width, int height, int flags )
{
    if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_TIMER ) < 0 )
    {
        printf("Error: Failed to init SDL2: %s\n", 
                SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow(
            title,               //title
            //SDL_WINDOWPOS_UNDEFINED,    //init x pos
            x,
            y,
            width,                      
            height,
            flags           //window usable with OpenGL
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

    running = true;
    return true;
}

void Game::render()
{
    SDL_RenderClear  ( renderer );
    SDL_RenderPresent( renderer );
}

void Game::update()
{}

void Game::handleEvents() 
{
    SDL_Event e;
    while( SDL_PollEvent( &e ) )
    {
        if( e.type == SDL_QUIT )
        {
            quit();
        }
    }
}

void Game::clean()
{
    SDL_DestroyWindow   ( window );
    SDL_DestroyRenderer ( renderer );
    SDL_Quit();
}

void Game::quit()
{
    running = false;
}

bool Game::isRunning()
{
    return running;
}

