#include "phb.h"
phb::phb() :jiemian() {
	/*fopen_s(&p, "./phb.txt", "r");*/
	//��ʼ��
	settextstyle(30, 0, _T("Consolas"));
	setbkmode(TRANSPARENT);
}
void phb::print() {
	
	fillroundrect(100, 100, 500, 700,20,20);
	putimage(200, 600, &tp);
	outtextxy(100, 75, "����");
	outtextxy(170, 75, "����");
	outtextxy(270, 75, "�÷�");
	ifstream myfile("./phb.txt");//������ķ�ʽ���ļ�
	for (int i = 0; i < 10; i++) {
		char ii[7];
		/*fscanf_s(p, "%s", &n, 10);
		fscanf_s(p, "%s", &s, 10);
		*/
		_itoa_s(i + 1, ii, 6, 10);
		string nn, ss;
		if (getline(myfile, nn)) /*��ȡ�ļ�����*/{
			getline(myfile, ss);
		}
		else break;
	
		outtextxy(100, 100 + i * 50, ii);
		outtextxy(200, 100 + i * 50, nn.c_str());
		outtextxy(300, 100 + i * 50, ss.c_str());
		/*if (feof(p))break;*/
	}
	/*fclose(p);*/
}
bool phb::start() {
	setlinecolor(YELLOW);
	setfillcolor(BLUE);
	load();
	print();
	while (1) {

		FlushBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 600 && m.y <= 700) /*��������*/{
			Sleep(200);
		return true;
		}
	}
}
void phb::load() {
	loadimage(&tp, "./IMAGE/fh.jpg");
}