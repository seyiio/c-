#pragma once
#include "fj.h"
class dj :public fj {
public:
	dj(int x, int y, int w, int h, int health, int speed, int d);
	void move();
private:
	int m;//�ƶ��ľ���
	int	t;//ͣ������ʱ��
	int d1;//�ƶ�����
};

