#include "js.h"
void js::print() {
	fillroundrect(100, 100, 500, 700, 5, 5);
	putimage(200, 600, &tp);
	outtextxy(100, 100 , "您的得分为：");
	outtextxy(450,100,temp);

}
bool js::start() {
	//初始化
	setlinecolor(YELLOW);
	setfillcolor(BLUE);
	load();
	setbkmode(TRANSPARENT);
	settextstyle(70, 0, _T("Consolas"));

	//绘制
	print();
	while (1) {

		FlushBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 600 && m.y <= 700)/*检测鼠标点击按钮*/ {
			Sleep(200);
			return true;
		}
	}
}
void js::load() {
	loadimage(&tp, "./IMAGE/fh.jpg");
}
js::js(int s,string name){
	/*fopen_s(&p, "./phb.txt", "r");*/
	ifstream myfile("./phb.txt");//打开文件
	for (int i = 0; i <10;i++) {
		string n,ss;
		if (getline(myfile, n))/*获取文件内容*/{
			getline(myfile, ss);
			pl.push_back(*(new player(n, ss)));//生成数据对象
		}
		else break;
		/*fscanf_s(p, "%s", &n, 10);
		if (feof(p))break;
		fscanf_s(p, "%s", &ss, 10);
		pl.push_back(*(new player(n,ss)));
		fclose(p);
		c语言文件读写
		*/	
	}
	pl.push_back(*(new player(name, s)));/*生成当前结束的玩家数据*/
	_itoa_s(s, temp, 10, 10);
	sort();//排序
	myfile.close();//关闭读取文件
	writein();//写入数据
	start();//绘制界面
}

//冒泡法排序
void js::sort() {
	if (!(pl.size() == 1)) {
		for (int i = 0; i < pl.size()-1; i++) {
			for (int j = pl.size()-1; j > 0; j--)
				if (pl[j].comp(pl[j - 1])) {
					swap(pl[j], pl[j - 1]);
				}
		}
	}
}
void js::writein() {
	/*
	fopen_s(&p, "./phb.txt", "w");
	for (int i = 0; i < 10; i++) {
		char temp[11];
		pl[i].getn().copy(temp, 10);
		temp[10] = '\0';
		fputs(temp, p);
		fputs("\n", p);
		fputs(pl[i].gets, p);
		fputs("\n", p);
	}
	fclose(p);
	*/
	ofstream ofile("./phb.txt", ios::out);//文件以输出方式打开
	for (int i = 0; i < pl.size(); i++)
	{
		ofile << pl[i].getn() << endl << pl[i].gets() << endl;//输出数据
	}
	ofile.close();
}