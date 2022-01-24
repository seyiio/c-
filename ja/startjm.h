#pragma once
#include "jiemian.h"
#include"gkk.h"
#include"phb.h"
#include"js.h"
class startjm :private jiemian {
public:
	startjm();
	void print();
	void load();
	bool start();
private:
	IMAGE tp[3];

};