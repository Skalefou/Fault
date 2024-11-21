/**
 * @file Game.c
 * @brief Game management
 * @details Contains the main loop of the game and all the functions to manage the game as a whole
 */

#include <stdlib.h>
#include <SDL2/SDL.h>
#include "Game.h"
#include "WindowManager.h"
#include "Renderer.h"

Game *Game_getInstance()
{
    static Game instance;
    static int init = 0;
    if (!init)
    {
        instance.runningApp = 1;
        init = 1;
    }

    return &instance;
}

Game *Game_init()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        Game_quit(EXIT_FAILURE);
    }
    WindowManager *windowManager = WindowManager_getInstance();
    Game *game = Game_getInstance();
    return game;
}

void Game_loop()
{
    Game *game = Game_init();

    while (game->runningApp)
    {
        while (SDL_PollEvent(&game->event))
        {
            if (game->event.type == SDL_QUIT)
            {
                game->runningApp = 0;
            }
        }

        Renderer_render();
    }

    Game_quit(EXIT_SUCCESS);
}

void Game_quit(int status)
{
    SDL_Quit();
    exit(status);
}
