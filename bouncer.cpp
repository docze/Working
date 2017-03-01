#include "bouncer.h"


bouncer::bouncer(int size)
{
	this->size = size;
	this->x = ( WIDTH / 2.0) - (size / 2.0) ;
	this->y = ( HEIGHT / 2.0) - (size / 2.0) ;

	this->dx = -4.0;
	this->dy = 4.0; 
	char *path = "pacman.png";
	image = al_load_bitmap(path);
}
float bouncer::getX(){
	return x;
}
float bouncer::getY(){
	return y;
}

int bouncer::getSize(){
	return size;
}
void bouncer::move(){
	 if(x < 0 || x > WIDTH - size) {
            dx = -dx;
         }

    if(y < 0 || y > HEIGHT - size) {
			dy = -dy;
    }
			x += dx;
			y += dy;
}
ALLEGRO_BITMAP *bouncer::adres(){
	return this->image;
}


bouncer::~bouncer(void)
{
	al_destroy_bitmap(this->image);
}
void bouncer::anim(){
	if(is)	image = al_load_bitmap("pacman.png");
	else image = al_load_bitmap("pacmanClose.png");
	is = !is;
}
void bouncer::moveUp(){
	y -= dy;
}
void bouncer::moveDown(){
	y += dy;
}
void bouncer::moveRight(){
	x -= dx;
}
void bouncer::moveLeft(){
	x  += dx;
}	