#include "character.h"

character::character(int x, int y, int w, int h, int health, int speed, int dd) :x(x), y(y), w(w), h(h), health(health), speed(speed) {
	//初始化
	d = dd;
	live = true;
	boom = true;
}
bool character::pz(character *a,int t/*每次碰撞的间隔*/) {
	static DWORD t1 = 0, t2 = 0;
	if (x < a->x + a->w / 2 && a->x < x + w && y < a->y &&  a->y < y + h && t2 - t1>t) {
		health -=a-> d;
		t1 = t2;
		if (health <= 0) {
			boom = false;//检测是否被击毁
		}
		return true;
	}
	else {
		t2 = GetTickCount();//返回操作系统启动到现在所经过的毫秒数
		return false;
	}

}
int character::getx() {
	return x;
}
int character::gety() {
	return y;
}
void character::print(IMAGE t) {
	putimage(x, y, &t);
}

