#include "js.h"
void js::print() {
	fillroundrect(100, 100, 500, 700, 5, 5);
	putimage(200, 600, &tp);
	outtextxy(100, 100 , "���ĵ÷�Ϊ��");
	outtextxy(450,100,temp);

}
bool js::start() {
	//��ʼ��
	setlinecolor(YELLOW);
	setfillcolor(BLUE);
	load();
	setbkmode(TRANSPARENT);
	settextstyle(70, 0, _T("Consolas"));

	//����
	print();
	while (1) {

		FlushBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 600 && m.y <= 700)/*����������ť*/ {
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
	ifstream myfile("./phb.txt");//���ļ�
	for (int i = 0; i <10;i++) {
		string n,ss;
		if (getline(myfile, n))/*��ȡ�ļ�����*/{
			getline(myfile, ss);
			pl.push_back(*(new player(n, ss)));//�������ݶ���
		}
		else break;
		/*fscanf_s(p, "%s", &n, 10);
		if (feof(p))break;
		fscanf_s(p, "%s", &ss, 10);
		pl.push_back(*(new player(n,ss)));
		fclose(p);
		c�����ļ���д
		*/	
	}
	pl.push_back(*(new player(name, s)));/*���ɵ�ǰ�������������*/
	_itoa_s(s, temp, 10, 10);
	sort();//����
	myfile.close();//�رն�ȡ�ļ�
	writein();//д������
	start();//���ƽ���
}

//ð�ݷ�����
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
	ofstream ofile("./phb.txt", ios::out);//�ļ��������ʽ��
	for (int i = 0; i < pl.size(); i++)
	{
		ofile << pl[i].getn() << endl << pl[i].gets() << endl;//�������
	}
	ofile.close();
}