#include <stdlib.h>
#include <stdio.h>

#include "Graphics.h"
#include "cJSON.h"

Graphics *Graphics_getInstance() {
    static Graphics *instance = NULL;
    static int init = 0;
    if (!init) {
        instance = malloc(sizeof(Graphics));

        instance->tileCount = 0;
        instance->atlasLoadedCount = 0;
        instance->atlasLoaded = NULL;
        instance->tiles = NULL;
        
        init = 1;
    }
    return instance;
}

char *Graphics_readFile(const char *filename) {
    if (filename == NULL) {
        return NULL;
    }
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char *data = (char*)malloc(length + 1);
    if (data == NULL) {
        fclose(file);
        return NULL;
    }
    fread(data, 1, length, file);
    data[length] = '\0';
    fclose(file);
    return data;
}

void Graphics_LoadTiles(Graphics *graphics) {
    if (graphics == NULL) {
        return;
    }
    char *jsonStr = Graphics_readFile("data/textures/tiles/tiles.json");
    cJSON *json = cJSON_Parse(jsonStr);
    free(jsonStr);

    cJSON_Delete(json);
    graphics->tiles = malloc(sizeof(Texture) * graphics->tileCount);
}

void Graphics_freeAll() {
    Graphics *graphics = Graphics_getInstance();
    if (graphics == NULL) {
        return;
    }
    free(graphics);
}