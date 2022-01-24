#pragma once
#include "jiemian.h"
class phb :public jiemian
{
public:
	phb();
	void print();
	bool start();
	void load();
private:
	/*FILE *p;*/
	char n[11];
	char s[11];
	IMAGE tp;
};

