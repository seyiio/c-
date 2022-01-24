#include "dj.h"
dj::dj(int x, int y, int w, int h, int health, int speed, int d) :fj(x, y, w,h,health, speed ,d) {
	m = rand() % 150;//随机y移动的距离	
	t = m *2;//设置x移动的距离
	//随机一个方向
	if (rand() % 2) {
		d1 = 1;
	}
	else {
		d1 = -1;
	}
}
void dj::move() {
	//移动
	if (!m == 0) {
		y += speed;
		if (y > 800) {
			live = false;
		}
		m--;
	}
	else {
		t--;
		if (t%200==0)/*移动到一定距离转向*/ {
			d1 = -d1;
		}
		if (x>500) /*碰壁转向*/{
			d1 = -1;
		}
		else if (x < 0) /*碰壁转向*/{
			d1 = 1;
		}
		x += d1*speed;
		//x移动
		if (t <= 0) /*重新设置移动*/{
			m = rand() % 150;
			t = m*2 ;
		}
	}
}