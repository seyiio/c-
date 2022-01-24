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
	void sort();//对11个成绩进行排序
	void writein();//写入磁盘文件
private:
	IMAGE tp;
	string name;
	char temp[10];
	std::vector < player > pl;
	/*FILE *p;*/
};

