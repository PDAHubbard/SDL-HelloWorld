#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game
{
    public:

        static Game* Instance()
        {
            if( instance == 0 )
            {
                instance = new Game();
            }
            return instance;
        }

        bool init( const char* title, int x, int y, int width, int height, int flags );
        void update();
        void handleEvents();
        void render();
        void clean();
        void quit();

        bool isRunning();

        SDL_Window*   getWindow()   const { return window;   }
        SDL_Renderer* getRenderer() const { return renderer; }

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

        Game(){};
        ~Game(){};
        static Game* instance;

        bool running;
};

typedef Game _Game;

#endif
