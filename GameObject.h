#pragma once
#include <allegro5/allegro_primitives.h>
#include "Globals.h"
#include <string>
#include <malloc.h>

class GameObject{
	ID type_object;
	bool isLive, isCollidable;
protected:
	ALLEGRO_BITMAP *image;
	float	x, y,	// position
			angle;

	int width,
		height;

public:
	GameObject();
	GameObject::GameObject(char *path, int width, int height, bool isLive, bool isCollidable, float angle, float x, float y) :
		image(al_load_bitmap(path)), height(height), width(width), isLive(isLive), isCollidable(isCollidable), angle(angle), x(x), y(y){};
	~GameObject();
	void setX(float x);
	void setY(float y);
	void setXY(float x, float y);
	void setImage(ALLEGRO_BITMAP *image);
	void setImage(char *path);
	float getX();
	float getY();
	void  getSize(int &width , int &height);
	int  getWidth();
	int	 getHeight();
	virtual void draw();
};
