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
	wj p;/*玩家*/
	std::vector<zd*> dd;/*子弹数组*/
	std::vector<dj*> ed;/*敌人数组*/
	std::vector<bg*> bgg;/*补给数组*/
	IMAGE jj;/*玩家图片*/
	IMAGE zz;/*子弹*/
	IMAGE dji;/*敌人图片*/
	IMAGE gj;/*伤害补给图片*/
	IMAGE hf;/*回复补给图片*/
	IMAGE er;/*炸弹补给图片*/
	int s;//分数
	int n;//难度
	int boomn;//炸弹数量
};

