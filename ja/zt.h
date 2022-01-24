#pragma once
#include"jiemian.h"
class zt :public jiemian
{
public:
	zt();
	void print();
	void load();
	bool start();
private:
	IMAGE tp[2];
	bool z;
};

