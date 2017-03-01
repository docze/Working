#include <stdio.h>
#include <allegro5/allegro.h>
#include "Controller.h"
#include "Globals.h"
int main(int argc, char **argv)
{

	if(!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	Controller *controller = new Controller(30, 0, 10, 60);
	controller->loop();
	return 0;
}