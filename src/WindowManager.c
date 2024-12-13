/**
 * @file WindowManager.c
 * @brief WindowManager class implementation
 * @details Handles all window management
 */

#include "WindowManager.h"
#include "Game.h"

static int init = 0;

WindowManager *WindowManager_getInstance()
{
    static WindowManager instance;
    if (!init)
    {
        if (SDL_GetDisplayBounds(0, &instance.userScreen) != 0)
        {
            SDL_Log("Could not get display bounds: %s", SDL_GetError());
            Game_quit(EXIT_FAILURE);
        }

        instance.width = instance.userScreen.w;
        instance.height = instance.userScreen.h;

        if (SDL_CreateWindowAndRenderer(instance.width, instance.height, SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP, &instance.window, &instance.renderer) != 0)
        {
            SDL_Log("Could not create window and renderer: %s", SDL_GetError());
            Game_quit(EXIT_FAILURE);
        }
        SDL_SetWindowTitle(instance.window, "Fault");
        SDL_RenderSetLogicalSize(instance.renderer, SCREEN_LOGICAL_WIDTH, SCREEN_LOGICAL_HEIGHT);
        init = 1;
    }
    return &instance;
}

void WindowManager_free()
{
    if (!init)
    {
        return;
    }

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