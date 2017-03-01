#pragma once
#include <allegro5/allegro.h>
#include "Globals.h"
#include <string>
class bouncer
{

	ALLEGRO_BITMAP *image;
	float	x, y,
			dx, dy; 
	bool is;
	int size;
public:
	bouncer(int size);
	float getX();
	float getY();
	void anim();
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	int getSize();
	~bouncer(void);
	void move();
	ALLEGRO_BITMAP *adres();
};

