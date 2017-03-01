#include "Controller.h"

void Controller::tile_draw(float x, float y, float w, float h){
	al_draw_bitmap(al_load_bitmap("wall.png"), x, y, 0);
}

void Controller::tile_map_create(void){
	
	int x, y;
	tiles = al_create_bitmap(1024, 1024);
	al_set_target_bitmap(tiles);
	tile_draw(32,0, 32, 32);
	al_set_target_backbuffer(this->display);

	 for (y = 0; y < 100; y++) {
        for (x = 0; x < 100; x++) {
            tile_map[x + y * 100] = 1;
        }
    }
}

void Controller::tile_map_draw(void) {
    int x, y;
    float w, h;
    
    w = al_get_display_width(display);
    h = al_get_display_height(display);
    

    al_clear_to_color(al_map_rgb(R, G, B));

    for (y = 0; y < 100; y++) {
        for (x = 0; x < 100; x++) {
			if(tile_map[ x * y] == 1) tile_draw(x*15, y*15, 0, 0);
        }
    }
    
}
Controller::Controller(int r, int g, int b, int FPS) : R(r), G(g), B(b){
	this->initTimer(FPS);
	this->event_queue = al_create_event_queue();
	this->createWindow(r, g, b);




	 if(!al_init_primitives_addon()){
    }
	if(!event_queue){
		fprintf(stderr, "Nie udalo sie stworzyc kolejki zdarzen\n");
		this->~Controller();
	}

	al_install_keyboard();
	al_init_image_addon();
	

	//____________________________
	//	Event handling
	//____________________________

	al_register_event_source(this->event_queue, al_get_display_event_source(this->display)); 
	al_register_event_source(this->event_queue, al_get_timer_event_source(this->timer));
	al_register_event_source(this->event_queue, al_get_keyboard_event_source());
}


int Controller::initTimer(int FPS){
	timer = al_create_timer(1.0 / FPS);
	if(!timer) {
     fprintf(stderr, "failed to create timer!\n");
     return -1;
	}
	return 0;
}
void Controller::createWindow(int r, int g, int b){
	display = al_create_display(WIDTH, HEIGHT);
	
	

	al_clear_to_color(al_map_rgb(r,g,b));
}

Controller::~Controller(void)
{
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_timer(timer);
}
bool collision(GameObject *objA, GameObject *objB){
	if (objA->getX() < objB->getX() + objB->getWidth() &&
		objA->getX() + objA->getWidth() > objB->getX() &&
	   objA->getY() < objB->getY() + objB->getHeight() &&
	   objA->getHeight() + objA->getY() > objB->getY() ) {
		// collision detected!
		   printf("Kolizja!\n");
			return true;
	}
	return false;	
}

void Controller::loop(){
	bool  isEnd = true, redraw = true;
	char *path = "pacman";
	Characters pacman("pacman.png", 30, 30, true, true, 0, 15, WIDTH/2, HEIGHT/2, 5, 5);
	Characters sprite("slime.png", 30, 30, true, true, 0, 15, 405, 220, 5, 5);
	Characters sprite2("slime.png", 30, 30, true, true, 0, 15, 240, 240, 5, 5);
	pacman.setXY(380, 285);
	pacman.pushFrame("pacmanClose.png");
	pacman.popFrame();
	pacman.pushFrame("pacmanClose.png");
	bool key[4] = { false, false, false, false };
	int animTimer = 0;
	al_clear_to_color(al_map_rgb(R,G,B));
	ALLEGRO_EVENT ev;
	al_flip_display();
	al_start_timer(timer);
		char maps[MAX_LIN][MAX_COL] = {{"XXXXXXXXXXXXXXXXXXXXXXXXXXX"},
									   {"X            X            X"},
									   {"X XXXX XXX X X XXXX XXXX  X"},
									   {"X X  X X   X      X X  X  X"},
									   {"X XXXX X  XX X XX X XXXX  X"},
									   {"X                         X"},
									   {"X XXXXX  X      X XXXXXX  X"},
									   {"X X      X      X         X"},
									   {"X   X X  XXXXXXXX         X"},
									   {"X X X X                   X"},
									   {"X     X  XXXXXXX          X"},
								       {"X XX X X    X             X"},
									   {"X XX X XXXX X             X"},
									   {"X                         X"},
									   {"XXXXXXXXXXXXXXXXXXXXXXXXXXX"}};
		char points[MAX_LIN][MAX_COL] = {{"XXXXXXXXXXXXXXXXXXXXXXXXXXX"},
									   {"X *****      X     *****  X"},
									   {"X XXXX XXX X X XXXX XXXX  X"},
									   {"X X  X X   X      X X  X  X"},
									   {"X XXXX X  XX X XX X XXXX  X"},
									   {"X                         X"},
									   {"X XXXXX  XX    XX XXXXXX  X"},
									   {"X X      X      X         X"},
									   {"X   X X  XXXXXXXX         X"},
									   {"X X X X                   X"},
									   {"X     X  XXXXXXX          X"},
								       {"X XX X X    X             X"},
									   {"X XX X XXXX X             X"},
									   {"X   **************        X"},
									   {"XXXXXXXXXXXXXXXXXXXXXXXXXXX"}};
		ALLEGRO_BITMAP *map = al_create_bitmap(800, 600);
		ALLEGRO_BITMAP *tile = al_load_bitmap("wall.png");
		ALLEGRO_BITMAP *point = al_load_bitmap("point.png");
		


		for(int row = 0; row < MAX_LIN; row++){
			for(int col = 0; col < MAX_COL; col++){
				if(maps[col][row] == 'X'){
					printf("%d, %d\n", row, col);
				}
			}
		}

	int y, x, gx, gy;

	while(isEnd){
		
		animTimer++;
		al_wait_for_event(event_queue, &ev);
		if( ev.type == ALLEGRO_EVENT_TIMER )
		{
			x = (int) pacman.getY();
			y = (int) pacman.getX();
			gx = (int) sprite.getY();
			gy = (int) sprite.getX();

		//	printf("%d, %d, %c\n", x/30, y/30, maps[x/30][y/30]);
			if(points[x/30][y/30] = '*'){
				points[x/30][y/30] = ' ';
			}


			if(key[KEY_UP] && maps[(x-16)/30][(y)/30] != 'X') pacman.moveUp();
			if(key[KEY_DOWN] &&  maps[(x+16)/30][(y)/30]  != 'X' )	pacman.moveDown();
			if(key[KEY_LEFT] &&  maps[(x)/30][(y-21)/30]  != 'X') pacman.moveLeft();
			if(key[KEY_RIGHT] &&  maps[(x)/30][(y+16)/30]  != 'X' ) pacman.moveRight();
			 

			if(sprite.getX() > pacman.getX() && maps[(gx)/30][(gy-21)/30] != 'X') sprite.moveLeft();
			if(sprite.getX() < pacman.getX() && maps[(gx)/30][(gy+16)/30] != 'X') sprite.moveRight();
			if(sprite.getY() > pacman.getY() && maps[(gx-16)/30][(gy)/30]  != 'X') sprite.moveUp();
			if(sprite.getY() < pacman.getY() && maps[(gx+16)/30][(gy)/30] != 'X' ) sprite.moveDown();
         redraw = true;
		}
		else if( ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE )
		{
			break;
		}else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			 switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
				   key[KEY_UP] = true;
				   break;

				case ALLEGRO_KEY_DOWN:
				   key[KEY_DOWN] = true;
				   break;

				case ALLEGRO_KEY_LEFT: 
				   key[KEY_LEFT] = true;
				   break;

				case ALLEGRO_KEY_RIGHT:
				   key[KEY_RIGHT] = true;
				   break;
			 }
		  }
		  else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
			 switch(ev.keyboard.keycode) {
				case ALLEGRO_KEY_UP:
				   key[KEY_UP] = false;
				   break;

				case ALLEGRO_KEY_DOWN:
				   key[KEY_DOWN] = false;
				   break;

				case ALLEGRO_KEY_LEFT: 
				   key[KEY_LEFT] = false;
				   break;

				case ALLEGRO_KEY_RIGHT:
				   key[KEY_RIGHT] = false;
				   break;
				    
			 }
		  }else if(ev.keyboard.keycode == ALLEGRO_KEY_J){
				printf("\naktualne: %d, %d\n", x, y);
				printf("\npodzielone; %d, %d\n", x/30, y/30);
				printf("lewy margines: %d, %d\n", (x-30)/30, y/30); 
				printf("prawy margines: %d, %d\n", (x+30)/30, y/30);
				printf("dolny margines: %d, %d\n", x/30, (y+30)/30);
				printf("gorny margines: %d, %d\n", x/30, (y-30)/30);
				printf("%c\n", maps[x/30][y/30]);
		  }else if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
			printf("escape\n");
		  }
		  if(collision(&pacman, &sprite)){
			  pacman.setXY(20*20, 20*20);
		  }

       

		if( redraw &&  al_is_event_queue_empty(event_queue)){
			redraw = false;
			al_clear_to_color(al_map_rgb(R, G, B));
			for(int row = 0; row < MAX_LIN; row++){
			for(int col = 0; col < MAX_COL; col++){
				if(maps[row][col] == 'X'){
					al_draw_bitmap(tile, col*30, row*30, NULL);
					}
				if(points[row][col] == '*'){
						al_draw_bitmap(point, col*30, row*30, NULL);
					}
				}
			}
			pacman.draw(animTimer);
			sprite.draw(0);
			al_flip_display();
		}
	}
}