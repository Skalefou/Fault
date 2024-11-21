/*
 * @file WindowManager.h
 * @brief WindowManager class
 * @copydetails WindowManager.c
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>

typedef struct {
    int width;
    int height;
    SDL_Rect userScreen;
    SDL_Window *window;
    SDL_Renderer *renderer;
} WindowManager;

/**
 * @brief Get the WindowManager instance
 * @return The WindowManager instance
 */
WindowManager *WindowManager_getInstance();

/**
 * @brief Free the WindowManager instance
 */
void WindowManager_free();

void Window

#endif