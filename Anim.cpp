#include "Anim.h"


Anim::Anim(char *path, int delay) : frameDelay(delay){
	curFrame = 0;
	countFrame = 1;
	printf("%d\n", countFrame);
	frameList = new char*[1];
	frameList[curFrame] = path;
}
Anim::Anim(char **pathList, int sizeList, int delay) : frameDelay(delay), countFrame(sizeList){
	curFrame = 0;
	countFrame = 1;
	frameList = new char*[countFrame];
	for(int i = 0; i < countFrame; i++) pathList[i] = (pathList[i]);
}

void Anim::pushFrame(char *path){
	printf("%d\n", countFrame);
	char **memList = new char*[countFrame + 1];
	if(frameList){
		for(int i = 0 ; i < countFrame; i++){
			memList[i] = frameList[i];
		}
	}
	memList[ countFrame ] = path;
	frameList = memList;
	countFrame++;
}
void Anim::popFrame(){
	if( countFrame  == 1 ){
		delete [] frameList[0];
		frameList = NULL;
	}
	else if(countFrame > 1 ){
		char **memList = new char*[countFrame - 1];
		for(int i = 0; i < countFrame; i++) memList[i] = frameList[i]; 
		frameList = memList;
		countFrame--;
	}
}
Anim::~Anim(){
	for(int i = 0; i < countFrame; i++)	delete [] frameList[i];
}

char *Anim::getNextFrame(){
	curFrame++;
	if(curFrame  == countFrame ) curFrame = 0;
	return frameList[curFrame];
}