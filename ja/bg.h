#pragma once
#include "character.h"

class bg :
	public character //补给类
{
public:
bg();
void move();//移动
int gid();//返回id
private:
int id;
};