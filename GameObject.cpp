#include "GameObject.h"


GameObject::GameObject(){
	image = NULL;
	isCollidable = false;
	isLive = false;
	x = WIDTH / 2;
	y =	HEIGHT / 2;
	width = 0;
	height = 0;
	angle = 0;
}

void GameObject::setImage(char *path){
	image = al_load_bitmap(path);
}
void GameObject::setImage(ALLEGRO_BITMAP *image){
	this->image = image;
}

float GameObject::getX(){
	return x;
}
float GameObject::getY(){
	return y;
}

void GameObject::getSize(int &width, int &height){
	width = this->width;
	height = this->height;
}
int GameObject::getHeight(){
	return this->height;
}
int GameObject::getWidth(){
	return this->width;
}
void GameObject::setXY(float x, float y){
	this->x = x;
	this->y = y;
}


void GameObject::draw(){
	al_draw_rotated_bitmap(image, 30, 30, x, y, angle, 0); 
}
GameObject::~GameObject(){
	delete image;
}