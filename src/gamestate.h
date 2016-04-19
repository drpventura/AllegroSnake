/*
 * gamestate.h
 *      Author: Phil Ventura, Ph.D. <venturap@palmbeachstate.edu>
 *
 * Use this file to define your gamestate structure.
 * NOTE: There is no gamestate.c
 */

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include "darray.h"

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

// screen dimensions
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

// size of each "block" on the board
#define BLOCK_SIZE 20

// size of the board in rows and columns
#define NUM_ROWS SCREEN_HEIGHT / BLOCK_SIZE
#define NUM_COLS SCREEN_WIDTH / BLOCK_SIZE

// Size of the gamestate keys array
#define NUM_KEYS 3

/**
 * Enumeration used for indexing into the gamestate keys array.
 */
enum KEYS{LEFT, RIGHT, PAUSE};

/**
 * A point in the Cartesian plane.
 */
typedef struct point_t {
	int x;
	int y;
} point_t;

/**
 *  A position on the board.
 */
typedef struct position_t {
	int row;
	int col;
} position_t;

/**
 * Struct to represent the state of the game
 */
typedef struct gamestate_t {
	//==============================================
	// ALLEGRO VARIABLES
	//==============================================
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	ALLEGRO_FONT *fpsFont;
    ALLEGRO_COLOR bgcolor;

	//==============================================
	// RENDER/DONE VARIABLES
	//==============================================
	bool done;
	bool render;

	//==============================================
	// FPS VARIABLES
	//==============================================
	float gameTime;
	int frames;
	int gameFPS;

	// TODO: Your additional fields here
	bool keys[3];

	position_t headPos;
} gamestate_t;

#endif /* GAMESTATE_H_ */
