#pragma once
#include "character.h"

class bg :
	public character //������
{
public:
bg();
void move();//�ƶ�
int gid();//����id
private:
int id;
};