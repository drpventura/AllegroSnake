/*
 * allegro_shell.h
 *      Author: Phil Ventura, Ph.D. <venturap@palmbeachstate.edu>
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "gamestate.h"

#ifndef ALLEGRO_SHELL_H_
#define ALLEGRO_SHELL_H_

//=============================================================================
// These functions are to be implemented by the user in some .c file.

/**
 * Handle keyboard input (key down or key up), except for ESCape key.
 */
void al_user_keyboard_input(gamestate_t *gs, ALLEGRO_EVENT *ev);

/**
 * Update the game logic.
 */
void al_user_update_game(gamestate_t *gs);

/**
 * Render the game.
 */
void al_user_render_game(gamestate_t *gs);

// ============================================================================

/**
 * Starts and inits allegro (and modules)
 */
void al_shell_startup_allegro(gamestate_t *gs, int width, int height, int fps);

/**
 * Cleans up allegro (and other) dynamic memory
 */
void al_shell_cleanup(gamestate_t *gs);

/**
 * The game loop.
 */
void al_shell_gameloop(gamestate_t *gs);

#endif /* ALLEGRO_SHELL_H_ */
