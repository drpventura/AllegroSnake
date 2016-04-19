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

// A point in the Cartesian plane.
typedef struct point_t {
	int x;
	int y;
} point_t;

// A position on the board.
typedef struct position_t {
	int row;
	int col;
} position_t;

/**
 * Returns the point corresponding to the given row, col.
 */
point_t to_point(int row, int col);

/**
 * Returns the position (row, col) corresponding to the given x, y.
 */
position_t to_position(int x, int y);

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
 * Draws gridlines on the board (for debugging).
 */
void drawGrid() {
	for (int r = 0; r < NUM_ROWS; r++) {
		al_draw_line(0, r * BLOCK_SIZE, SCREEN_WIDTH, r * BLOCK_SIZE, al_map_rgb(255, 255, 255), 0);
	}
	for (int c = 0; c < NUM_COLS; c++) {
		al_draw_line(c * BLOCK_SIZE, 0, c * BLOCK_SIZE, SCREEN_HEIGHT, al_map_rgb(255, 255, 255), 0);
	}
} // end drawGrid =============================================================

/**
 * Render the game.
 */
void al_user_render_game(gamestate_t *gs) {
	point_t head_pt = to_point(gs->headPos.row, gs->headPos.col);

	al_draw_filled_circle(gs->headPos, gs->headY + BLOCK_SIZE / 2, gs->headX + BLOCK_SIZE, gs->headY + BLOCK_SIZE, al_map_rgb(255, 0, 0));

	drawGrid();

} // end al_user_render_game ==================================================

point_t to_point(int row, int col) {
	point_t result = { col * BLOCK_SIZE, row * BLOCK_SIZE };
	return result;
} // end to_point =============================================================

position_t to_position(int x, int y) {
	position_t result = { y / BLOCK_SIZE, x / BLOCK_SIZE };
	return result;
} // end to_position ==========================================================
