#pragma once
#include "jiemian.h"
#include "wj.h"
#include"zd.h"
#include "dj.h"
#include"zt.h"
#include"bg.h"
class gkk :private jiemian {
public:
	gkk(LPCTSTR path);
	void print();
	void load();
	bool start();
	int gets() { return s; }
private:
	wj p;/*���*/
	std::vector<zd*> dd;/*�ӵ�����*/
	std::vector<dj*> ed;/*��������*/
	std::vector<bg*> bgg;/*��������*/
	IMAGE jj;/*���ͼƬ*/
	IMAGE zz;/*�ӵ�*/
	IMAGE dji;/*����ͼƬ*/
	IMAGE gj;/*�˺�����ͼƬ*/
	IMAGE hf;/*�ظ�����ͼƬ*/
	IMAGE er;/*ը������ͼƬ*/
	int s;//����
	int n;//�Ѷ�
	int boomn;//ը������
};

