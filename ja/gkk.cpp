#include "gkk.h"
gkk::gkk(LPCTSTR path ):  jiemian(path), p() {
	/*��ʼ��*/
	boomn = 3;
	load();/*����ͼƬ*/
	start();
	
}
void gkk::print() {
	putimage(0, 0, &background);/*���Ʊ���ͼƬ*/
	p.print(jj);/*�������*/

	//������Ϣ
	char ii[7];
	outtextxy(450, 0, "����ֵ��");
	_itoa_s(boomn, ii, 6, 10);
	outtextxy(370, 0, "ը������");
	outtextxy(425, 0, ii);
	char heal[8];
	_itoa_s(p.gethl(), heal, 7, 10);
	outtextxy(510, 0,heal);
	_itoa_s(s, ii, 6, 10);
	outtextxy(530, 0, "�÷֣�");
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
	BeginBatchDraw();//��ʼ������ͼ
	while (1) {
		if (!p.gb())/*�ж�����Ƿ���*/ {
			return true;
		}
		n = 1 + s /20;/*��̬�Ѷ�*/
		print();//����
		p.move();//����ƶ�
		int r = rand() % 10000;
		if (r < 55)/* ��������*/ {
			ed.push_back(new dj(rand() % 600, 0, 100, 100, n, 3,1+n/2));
		}
		if (r < 20)/*��������*/ {
			bgg.push_back(new bg());
		}
		//������������
		for (std::vector<bg*>::const_iterator it = bgg.begin(); it != bgg.end(); it++)
		{
			if ((**it).living())/*�Ƿ���*/ {
				(**it).move();//�ƶ�
				switch ((*it)->gid())/*����*/ {
				case 0://�ظ�����
					(**it).print(hf);
					break;
				case 1://�˺�����
					(**it).print(gj);
					break;
				case 2://ը������
					(**it).print(er);
					break;
				}
			}
			if (p.pz(*it,0))/*�������ײ���*/ {
				switch ((*it)->gid())/*�����ж�*/ {
				case 0:
					p.ch(n);
					break;
				case 1:
					p.ad();
					break;
				case 2:
					boomn++;

				}
				if (!(it == --bgg.end())) /*�ж��Ƿ������һ������ָ���ָ��*/{
					it = bgg.erase(it);
				}
				else
				{
					bgg.erase(it);
					break;
				}
			}
		}
		//��������
		for (std::vector<dj*>::const_iterator iter = ed.begin(); iter != ed.end(); iter++) 
		{
			if ((**iter).living())/*�ж��Ƿ�Խ��*/ {
				(**iter).move();
				(**iter).print(dji);
			}
			//�����ӵ�����
			for (std::vector<zd*>::const_iterator iter1 = dd.begin(); iter1 != dd.end(); iter1++) {
				//�ж��Ƿ����ӵ���ײ
				if ((*iter)->pz(*iter1,100)) {
					if (!(iter1 == --dd.end()))/*�ж��Ƿ������һ��*/ {
						iter1 = dd.erase(iter1);
					}
					else
					{
						dd.erase(iter1);
						break;
					}
				}

			}
			if (!(**iter).gb()) /*�ж��Ƿ񱻻���*/{
				if (!(iter == --ed.end())) {
					iter = ed.erase(iter);
				}
				else
				{
					ed.erase(iter);
				}
				s += n; break;
			}
			if (!(**iter).living())/*Խ��ɾ��*/ {
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
			p.pz(*iter,400);/*�л��������ײ���*/

		}
		if (MouseHit())/*����Ƿ���*/ {
			MOUSEMSG m = GetMouseMsg();
			if (m.mkLButton&&m.x >= 0 && m.x <= 50 && m.y >= 0 && m.y <= 50) {
				zt i;/*������ͣ����*/
				if (i.start()) {
					return false;/*���ؿ�ʼ����*/
				}
			}
		}
		//�����ӵ�����
		for (std::vector<zd*>::const_iterator iter = dd.begin(); iter != dd.end(); iter++) {
			if ((**iter).living())/*�ж�Խ��*/ {
				(**iter).move();
				(**iter).print(zz);
			}/*Խ��ɾ��*/
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
		if (p.shoot())/*����Ƿ����*/ {
			
				dd.push_back(new zd(p.getx() + 50, p.gety(), 1, 10,p.getd()));//�����ӵ�
		}
		if (p.bboom()&&boomn>0)/*�ж�����Ƿ�ʹ��ը��*/ {
			s += ed.size()*n;
			ed.clear();
			boomn--;
		}
		FlushBatchDraw();//ִ��δ��ɵĻ�������
		Sleep(8);//˯��8ms
	}
}