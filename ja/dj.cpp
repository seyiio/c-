#include "dj.h"
dj::dj(int x, int y, int w, int h, int health, int speed, int d) :fj(x, y, w,h,health, speed ,d) {
	m = rand() % 150;//���y�ƶ��ľ���	
	t = m *2;//����x�ƶ��ľ���
	//���һ������
	if (rand() % 2) {
		d1 = 1;
	}
	else {
		d1 = -1;
	}
}
void dj::move() {
	//�ƶ�
	if (!m == 0) {
		y += speed;
		if (y > 800) {
			live = false;
		}
		m--;
	}
	else {
		t--;
		if (t%200==0)/*�ƶ���һ������ת��*/ {
			d1 = -d1;
		}
		if (x>500) /*����ת��*/{
			d1 = -1;
		}
		else if (x < 0) /*����ת��*/{
			d1 = 1;
		}
		x += d1*speed;
		//x�ƶ�
		if (t <= 0) /*���������ƶ�*/{
			m = rand() % 150;
			t = m*2 ;
		}
	}
}