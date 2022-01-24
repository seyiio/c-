#pragma once
#include "fj.h"
class wj :public fj
{
public:
	wj();
	void move();
	void ch(int n);
	bool shoot();//是否射击
	bool bboom();//是否使用炸弹

};

