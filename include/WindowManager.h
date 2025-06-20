/*
 * @file WindowManager.h
 * @brief WindowManager class
 * @copydetails WindowManager.c
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

#define SCREEN_LOGICAL_WIDTH 1920
#define SCREEN_LOGICAL_HEIGHT 1080

typedef struct {
    int width;
    int height;
    SDL_Rect userScreen;
    SDL_Window *window;
    SDL_Renderer *renderer;
} WindowManager;

/**
 * @brief Get the WindowManager instance, create it if it doesn't exist
 * @return The WindowManager instance
 */
WindowManager *WindowManager_getInstance();

/**
 * @brief Free the WindowManager instance
 */
void WindowManager_free();

#endif