#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "Texture.h"

typedef struct {
    char **atlasLoaded;
    Texture *tiles;
    int tileCount;
    int atlasLoadedCount;
} Graphics;

Graphics *Graphics_getInstance();
char *Graphics_readFile(const char *filename);
void Graphics_LoadTiles(Graphics *graphics);
void Graphics_freeAll();

#endif