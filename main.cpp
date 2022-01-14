#include <stdlib.h>
#include <time.h>
//#include "graphics.h"
#include "game.h"
//#include "world.h"
//#include "inputs.h"

const int FPS=60;
const float MS_PER_FRAME = 1000.0f / FPS;
Uint32 previous, current, lag, elapsed;

//int main( int argc, char** argv )
int main( )
{
	//Initialise random seed
	srand( time( NULL ) );

    if( _Game::Instance()->init( "Balloonacy", 
            SDL_WINDOWPOS_UNDEFINED,  
            SDL_WINDOWPOS_UNDEFINED,
            640,
            480,
            SDL_WINDOW_SHOWN ) )
    {
        previous = SDL_GetTicks();
        lag = 0;
	    while( _Game::Instance()->isRunning() )
	    {
            current = SDL_GetTicks();
            elapsed = current - previous;
            previous = current;
            lag += elapsed;

            printf("Lag: %u \n", lag);

            //process inputs
            _Game::Instance()->handleEvents(); 
            //update
            while( lag >= MS_PER_FRAME )
            {
                _Game::Instance()->update();
                lag -= MS_PER_FRAME;
            }
            //render
            _Game::Instance()->render();

	    }
    }
    else
    {
        printf( "Game init failed: %s\n", SDL_GetError() );
        return -1;
    }

    _Game::Instance()->clean();

	return 0;
}

