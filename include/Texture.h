/**
 * @file Texture.h
 * @brief Texture management
 * @details Contains all the functions related to textures (loading, rendering, etc.)
 */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>

void Texture_getInstance();
void Texture_LoadAll();
void Texture_FreeAll();

typedef struct {
    int width;
    int height;
    SDL_Texture *texture;
} Texture;

#endif
