#pragma once
#include"j.h"

class character {
protected:
	int x;//x坐标
	int y; //y坐标
	int health; //生命值
	int speed; //速度
	int w; //图片宽度
	int h;//图片高度
	int d;//伤害
	bool live; //是否存活
	bool boom;//是否被击毁
public:
	character(int x, int y,int w,int h, int health, int speed,int dd);
	virtual void move() = 0;//移动
	bool living() { return live; }//返回是否存活
	bool pz(character *a,int t );//碰撞检测，和碰撞类型
	int getx();//返回x坐标
	int gety();//返回y坐标
	void print(IMAGE t);
	bool gb() { return boom; }
	int gethl() {
		return health;
	}
	int getd() { return d; }
	void ad() { d++; }//增加伤害
};

