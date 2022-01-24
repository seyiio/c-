#include "gkk.h"
gkk::gkk(LPCTSTR path ):  jiemian(path), p() {
	/*初始化*/
	boomn = 3;
	load();/*载入图片*/
	start();
	
}
void gkk::print() {
	putimage(0, 0, &background);/*绘制背景图片*/
	p.print(jj);/*绘制玩家*/

	//绘制信息
	char ii[7];
	outtextxy(450, 0, "生命值：");
	_itoa_s(boomn, ii, 6, 10);
	outtextxy(370, 0, "炸弹数：");
	outtextxy(425, 0, ii);
	char heal[8];
	_itoa_s(p.gethl(), heal, 7, 10);
	outtextxy(510, 0,heal);
	_itoa_s(s, ii, 6, 10);
	outtextxy(530, 0, "得分：");
	outtextxy(570, 0, ii);
}
void gkk::load() {
	loadimage(&jj, "./IMAGE/wj.jpg");
	loadimage(&zz, "./IMAGE/zd.jpg");
	loadimage(&dji, "./IMAGE/dj.jpg");
	loadimage(&hf, "./IMAGE/hf.jpg");
	loadimage(&gj, "./IMAGE/gj.jpg");
	loadimage(&er, "./IMAGE/er.jpg");
}
bool gkk::start() {
	BeginBatchDraw();//开始批量绘图
	while (1) {
		if (!p.gb())/*判断玩家是否存活*/ {
			return true;
		}
		n = 1 + s /20;/*动态难度*/
		print();//绘制
		p.move();//玩家移动
		int r = rand() % 10000;
		if (r < 55)/* 敌人生成*/ {
			ed.push_back(new dj(rand() % 600, 0, 100, 100, n, 3,1+n/2));
		}
		if (r < 20)/*补给生成*/ {
			bgg.push_back(new bg());
		}
		//遍历补给数组
		for (std::vector<bg*>::const_iterator it = bgg.begin(); it != bgg.end(); it++)
		{
			if ((**it).living())/*是否存活*/ {
				(**it).move();//移动
				switch ((*it)->gid())/*绘制*/ {
				case 0://回复补给
					(**it).print(hf);
					break;
				case 1://伤害补给
					(**it).print(gj);
					break;
				case 2://炸弹补给
					(**it).print(er);
					break;
				}
			}
			if (p.pz(*it,0))/*与玩家碰撞检测*/ {
				switch ((*it)->gid())/*种类判断*/ {
				case 0:
					p.ch(n);
					break;
				case 1:
					p.ad();
					break;
				case 2:
					boomn++;

				}
				if (!(it == --bgg.end())) /*判断是否是最后一个以免指向空指针*/{
					it = bgg.erase(it);
				}
				else
				{
					bgg.erase(it);
					break;
				}
			}
		}
		//遍历敌人
		for (std::vector<dj*>::const_iterator iter = ed.begin(); iter != ed.end(); iter++) 
		{
			if ((**iter).living())/*判断是否越界*/ {
				(**iter).move();
				(**iter).print(dji);
			}
			//遍历子弹数组
			for (std::vector<zd*>::const_iterator iter1 = dd.begin(); iter1 != dd.end(); iter1++) {
				//判断是否与子弹碰撞
				if ((*iter)->pz(*iter1,100)) {
					if (!(iter1 == --dd.end()))/*判断是否是最后一个*/ {
						iter1 = dd.erase(iter1);
					}
					else
					{
						dd.erase(iter1);
						break;
					}
				}

			}
			if (!(**iter).gb()) /*判断是否被击毁*/{
				if (!(iter == --ed.end())) {
					iter = ed.erase(iter);
				}
				else
				{
					ed.erase(iter);
				}
				s += n; break;
			}
			if (!(**iter).living())/*越界删除*/ {
				if (!(iter == --ed.end())) {
					iter = ed.erase(iter);
				}
				else
				{
					ed.erase(iter);
					break;
				}
				continue;
			}
			p.pz(*iter,400);/*敌机与玩家碰撞检测*/

		}
		if (MouseHit())/*鼠标是否点击*/ {
			MOUSEMSG m = GetMouseMsg();
			if (m.mkLButton&&m.x >= 0 && m.x <= 50 && m.y >= 0 && m.y <= 50) {
				zt i;/*生成暂停界面*/
				if (i.start()) {
					return false;/*返回开始界面*/
				}
			}
		}
		//遍历子弹数组
		for (std::vector<zd*>::const_iterator iter = dd.begin(); iter != dd.end(); iter++) {
			if ((**iter).living())/*判读越界*/ {
				(**iter).move();
				(**iter).print(zz);
			}/*越界删除*/
			else {
				if (!(iter == --dd.end())) {
					iter = dd.erase(iter);
				}
				else
				{
					dd.erase(iter);
					break;
				}
			}
			
		}
		if (p.shoot())/*玩家是否射击*/ {
			
				dd.push_back(new zd(p.getx() + 50, p.gety(), 1, 10,p.getd()));//生成子弹
		}
		if (p.bboom()&&boomn>0)/*判断玩家是否使用炸弹*/ {
			s += ed.size()*n;
			ed.clear();
			boomn--;
		}
		FlushBatchDraw();//执行未完成的绘制任务
		Sleep(8);//睡眠8ms
	}
}