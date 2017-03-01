#include "Characters.h"


void Characters::moveUp(){
	y -= dy;
}
void Characters::moveDown(){
	y += dy;
}
void Characters::moveRight(){
	x += dx;
}
void Characters::moveLeft(){
	x  -= dx;
}	

void Characters::draw(int i){
	al_draw_rotated_bitmap(image, (width / 2),(height / 2), x, y, angle, 0); 
	if( ! (i%frameDelay) )	setImage(getNextFrame());
}