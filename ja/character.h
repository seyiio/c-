#pragma once
#include"j.h"

class character {
protected:
	int x;//x����
	int y; //y����
	int health; //����ֵ
	int speed; //�ٶ�
	int w; //ͼƬ���
	int h;//ͼƬ�߶�
	int d;//�˺�
	bool live; //�Ƿ���
	bool boom;//�Ƿ񱻻���
public:
	character(int x, int y,int w,int h, int health, int speed,int dd);
	virtual void move() = 0;//�ƶ�
	bool living() { return live; }//�����Ƿ���
	bool pz(character *a,int t );//��ײ��⣬����ײ����
	int getx();//����x����
	int gety();//����y����
	void print(IMAGE t);
	bool gb() { return boom; }
	int gethl() {
		return health;
	}
	int getd() { return d; }
	void ad() { d++; }//�����˺�
};

