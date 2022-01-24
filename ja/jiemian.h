#pragma once
#include"j.h"
class jiemian {
protected:
	IMAGE background;
public:
	jiemian(LPCTSTR path);
	jiemian();
	virtual void print() = 0;
	virtual void load() = 0;
	virtual bool start() = 0;
};