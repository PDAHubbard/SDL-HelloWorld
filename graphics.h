#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Graphics
{
    static const int WIDTH, HEIGHT;

    SDL_Window* window;
    SDL_Renderer* renderer;

    bool init_sdl();

public:
    Graphics();
    void clear_screen();
    void present_renderer();

    int get_width();
    int get_height();
    ~Graphics();
};

#endif

