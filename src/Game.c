#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Game.h"
#include "WindowManager.h"

void Game_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        Game_quit(EXIT_FAILURE);
    }
    WindowManager *windowManager = WindowManager_getInstance();
}

void Game_loop()
{
    Game_init();
    Game_quit(EXIT_SUCCESS);
}

void Game_quit(int status)
{
    SDL_Quit();
    exit(status);
}
