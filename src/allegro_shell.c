/*
 * allegro_shell.c
 *      Author: Phil Ventura, Ph.D. <venturap@palmbeachstate.edu>
 */

#include "allegro_shell.h"

/**
 * "Private" helper function called by game loop.
 */
void al_shell_update_game(gamestate_t *gs) {
	//==============================================
	// DO USER UPDATE GAME CODE
	//==============================================
	al_user_update_game(gs);

	//==============================================
	// UPDATE FPS
	gs->frames++;
	if(al_current_time() - gs->gameTime >= 1)
	{
		gs->gameTime = al_current_time();
		gs->gameFPS = gs->frames;
		gs->frames = 0;
	}
	//=====================
} // end allegroShellUpdateGame ===============================================

/**
 * "Private" helper function called by game loop.
 */
void al_shell_render_game(gamestate_t *gs) {
	gs->render = false;

	//==============================================
	// DO USER RENDERING
	//==============================================
	al_user_render_game(gs);

	//==============================================
	// DRAW FPS
	//==============================================
	al_draw_textf(gs->fpsFont, al_map_rgb(255, 0, 255), 5, 5, 0, "FPS: %i", gs->gameFPS);	//display FPS on screen

	//==============================================
	// FLIP BUFFERS
	//==============================================
	al_flip_display();
	al_clear_to_color(gs->bgcolor);

} // end al_shell_render_game =================================================

/**
 * "Private" helper function
 * Returns true iff the user clicked the window's close button or hit the ESCape key, and false otherwise.
 */
boolean al_shell_is_quit_game(const ALLEGRO_EVENT *ev) {
	return ev->type == ALLEGRO_EVENT_DISPLAY_CLOSE ||
			(ev->type == ALLEGRO_EVENT_KEY_DOWN
					&& ev->keyboard.keycode == ALLEGRO_KEY_ESCAPE);
} // end isQuitGame ===========================================================

void al_shell_gameloop(gamestate_t *gs) {

	while (!gs->done) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(gs->event_queue, &ev);

		//==============================================
		// QUIT?
		//==============================================
		if (al_shell_is_quit_game(&ev)) {
			gs->done = true;
		}
		//==============================================
		// KEYBOARD INPUT?
		//==============================================
		else if (ev.type == ALLEGRO_EVENT_KEY_DOWN
				|| ev.type == ALLEGRO_EVENT_KEY_UP) {
			al_user_keyboard_input(gs, &ev);
		}
		//==============================================
		// UPDATE
		//==============================================
		else if(ev.type == ALLEGRO_EVENT_TIMER) {
			gs->render = true;
			al_shell_update_game(gs);
		}

		//==============================================
		//RENDER
		//==============================================
		if(gs->render && al_is_event_queue_empty(gs->event_queue)) {
			al_shell_render_game(gs);
		}
	} // end game loop

} // end gameLoop =============================================================

void al_shell_cleanup(gamestate_t *gs) {
	al_destroy_font(gs->fpsFont);
	al_destroy_timer(gs->timer);
	al_destroy_event_queue(gs->event_queue);
	al_destroy_display(gs->display);
} // end cleanup ==============================================================

void al_shell_startup_allegro(gamestate_t *gs, int width, int height, int fps) {
	//==============================================
	// CLEARING THE INITIAL VARIABLES
	//==============================================
	gs->display = NULL;
	gs->event_queue = NULL;
	gs->timer = NULL;
	gs->fpsFont = NULL;
	gs->done = false;
	gs->render = false;
	gs->gameTime = 0;
	gs->frames = 0;
	gs->gameFPS = 0;

	if(!al_init()) {							  //initialize Allegro
		al_show_native_message_box(NULL, "Allegro Error", "Could not initialize Allegro", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-1);
	}

	gs->display = al_create_display(width, height);  //create our display object

	if(!gs->display) {								  //test display object
		al_show_native_message_box(NULL, "Allegro Error", "Could not create display", NULL, NULL, ALLEGRO_MESSAGEBOX_ERROR);
		exit(-2);
	}

	//==============================================
	// ADDON INSTALL
	//==============================================
	al_install_keyboard();
	al_init_image_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_primitives_addon();
	al_init_native_dialog_addon();

	//==============================================
	// PROJECT & TIMER INIT
	//==============================================
	gs->fpsFont = al_load_font("arial.ttf", 18, 0);

	gs->event_queue = al_create_event_queue();
	gs->timer = al_create_timer(1.0 / fps);

	al_register_event_source(gs->event_queue, al_get_timer_event_source(gs->timer));
	al_register_event_source(gs->event_queue, al_get_keyboard_event_source());
	al_register_event_source(gs->event_queue, al_get_display_event_source(gs->display));

} // end startupAllegro =======================================================

