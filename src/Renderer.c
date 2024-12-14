/**
 * @file Renderer.c
 * @brief Renderer management
 * @details Contains all the functions related to rendering
 */

#include <SDL2/SDL.h>
#include "Renderer.h"

#include "WindowManager.h"

void Renderer_render()
{
    const WindowManager *windowManager = WindowManager_getInstance();

    SDL_RenderClear(windowManager->renderer);
    SDL_RenderPresent(windowManager->renderer);
}
