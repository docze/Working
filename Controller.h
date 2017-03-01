#pragma once
#include <stdio.h>
#include <allegro5/allegro.h>
#include "Globals.h"
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_native_dialog.h"
#include "Characters.h"
class Controller
{	
	int tile_map[100*100];
	ALLEGRO_BITMAP *tiles;
	ALLEGRO_DISPLAY *display;
	ALLEGRO_EVENT_QUEUE *event_queue;
	ALLEGRO_TIMER *timer;
	int rotate;
	enum MYKEYS {
		KEY_UP,
		KEY_DOWN,
		KEY_LEFT,
		KEY_RIGHT
	};
	bool get_event;
	int	R , G, B;
public:
	Controller(int r, int g, int b, int FPS);
	void createWindow(int r, int g, int b);
	int initTimer(int fps);
	void loop();
	ALLEGRO_EVENT_QUEUE* initQueue();
	int closeMain();
	~Controller(void);
	void  tile_draw(float x, float y, float w, float h);
	void tile_map_create(void);
	void Controller::tile_map_draw(void);
};

