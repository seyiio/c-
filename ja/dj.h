#pragma once
#include "fj.h"
class dj :public fj {
public:
	dj(int x, int y, int w, int h, int health, int speed, int d);
	void move();
private:
	int m;//移动的距离
	int	t;//停下来的时间
	int d1;//移动方向
};

