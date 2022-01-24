#pragma once
#include "character.h"

class fj :public character {
public:
	fj(int x, int y, int w, int h, int health, int speed, int d);
	virtual void move() = 0;
};
