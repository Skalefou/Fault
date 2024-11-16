/**
 * @file WindowManager.c
 * @brief WindowManager class implementation
 * @details Handles all window management
 */

#include "WindowManager.h"
#include "Game.h"

WindowManager *WindowManager_getInstance()
{
    static WindowManager instance;
    static int init = 0;
    if (!init)
    {
        if (SDL_GetDisplayBounds(0, &instance.userScreen) != 0)
        {
            SDL_Log("Could not get display bounds: %s", SDL_GetError());
            Game_quit(EXIT_FAILURE);
        }

        instance.width = instance.userScreen.w * 0.8;
        instance.height = instance.userScreen.h * 9 / 16;

        if (SDL_CreateWindowAndRenderer(instance.width, instance.height, SDL_WINDOW_SHOWN, &instance.window, &instance.renderer) != 0)
        {
            SDL_Log("Could not create window and renderer: %s", SDL_GetError());
            Game_quit(EXIT_FAILURE);
        }


        init = 1;
    }
    return &instance;
}

void WindowManager_free()
{
    WindowManager *windowManager = WindowManager_getInstance();
    if (windowManager->renderer != NULL)
    {
        SDL_DestroyRenderer(windowManager->renderer);
        windowManager->renderer = NULL;
    }
    if (windowManager->window != NULL)
    {
        SDL_DestroyWindow(windowManager->window);
        windowManager->window = NULL;
    }
}