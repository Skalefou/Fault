/**
 * @file Game.h
 * @brief Game management
 * @copydetails Game.c
 */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

typedef struct {
    int runningApp;
    SDL_Event event;
} Game;


/**
 * @brief Initialize the game
 */
Game *Game_init();

/**
 * @brief Main loop of the game
 */
void Game_loop();

/**
 * @brief Get the Game instance
 * @return The Game instance
 */
Game *Game_getInstance();

/**
 * @brief Quit the game
 * @param status The status to exit with
 */
void Game_quit(int status);

#endif
