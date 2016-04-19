#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "dbg.h"
#include "darray.h"
#include "gamestate.h"
#include "allegro_shell.h"

int main(void) {
	gamestate_t gamestate;
	gamestate.bgcolor = al_map_rgb_f(0, 0, 0);
	// init keys
	for (int i = 0; i < NUM_KEYS; i++) {
		gamestate.keys[i] = false;
	}

	al_shell_startup_allegro(&gamestate, SCREEN_WIDTH, SCREEN_HEIGHT, 60);

	// start the game
	al_start_timer(gamestate.timer);
	gamestate.gameTime = al_current_time();

	al_shell_gameloop(&gamestate);

	al_shell_cleanup(&gamestate);
} // end main =================================================================

/**
 * Handle keyboard input (key down or key up), except for ESCape key.
 */
void al_user_keyboard_input(gamestate_t *gs, ALLEGRO_EVENT *ev) {

	// TODO: add your input handling here

} // al_user_keyboard_input ===================================================

/**
 * Update the game logic.
 */
void al_user_update_game(gamestate_t *gs) {

	// TODO: add your game update logic here

} // end al_user_update_game ==================================================

/**
 * Render the game.
 */
void al_user_render_game(gamestate_t *gs) {

	// TODO: add your game rendering logic here

} // end al_user_render_game ==================================================
