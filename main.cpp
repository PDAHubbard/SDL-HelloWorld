#include <stdlib.h>
#include <time.h>
#include "graphics.h"
//#include <game/world.h>
//#include <input/inputs.h>

//int main( int argc, char** argv )
int main( )
{
	//Initialise random seed
	srand( time( NULL ) );

	Graphics graphics;

    SDL_Event e;

	bool loop = true;

	while( loop )
	{
        if( SDL_PollEvent( &e ) != 0 ) 
        {   
            //User requests quit
            if( e.type == SDL_QUIT )
                loop = false;
        }

		graphics.clear_screen();
//		graphics.render_entities( NULL, NULL );
//		graphics.render_overlay( NULL );
		graphics.present_renderer( );
	}

	return 0;
}

