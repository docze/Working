#pragma once
#include "GameObject.h"
#include "Anim.h"

class Characters : public GameObject, public Anim
{
	float dx, dy; // step 
public:
	Characters(char *path, int width, int height, bool isLive, bool isCollidable, float angle, int delay, float x, float y, float dx, float dy) :
			GameObject(path, width, height, isLive, isCollidable, angle, x, y), 
			Anim(path, delay), dx(dx), dy(dy) {};
	Characters(char **path, int size, int width, int height, bool isLive, bool isCollidable, float angle, int delay, float x, float y, float dx, float dy) :
			GameObject(path[0], width, height, isLive, isCollidable, angle, x, y), 
			Anim(path, size, delay), dx(dx), dy(dy) {};
	virtual void moveUp();
	virtual void moveDown();
	virtual void moveRight();
	virtual void moveLeft();
	void draw(int i);
};

