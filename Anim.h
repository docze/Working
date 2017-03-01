#pragma once
#include <stdio.h>
class Anim
{
protected:
	int countFrame,
		curFrame,
		frameDelay;
	char **frameList;
public:
	Anim() : countFrame(0), curFrame(0), frameDelay(0), frameList(NULL){};
	Anim(char *path, int delay);
	Anim(char **pathList, int sizeList, int delay);
	void setDelay();
	void pushFrame(char *path);
	void popFrame();
	char *getNextFrame();
	~Anim();
};

