#pragma once
#include "jiemian.h"
#include"player.h"

class js :
	public jiemian
{	
public:
	void print();
	bool start();
	void load();
	js(int s,string name);
	void sort();//��11���ɼ���������
	void writein();//д������ļ�
private:
	IMAGE tp;
	string name;
	char temp[10];
	std::vector < player > pl;
	/*FILE *p;*/
};

