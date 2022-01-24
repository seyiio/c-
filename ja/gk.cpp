#include "gk.h"
gk::gk ():jiemian("./IMAGE/gki.jpg") {
	Sleep(100);
	load();
	start();
}
void gk::print()
{
	putimage(0, 0, &background);
	putimage(200, 0, &tp[0]);
	putimage(200, 150, &tp[1]);
	putimage(200, 300, &tp[2]);
	putimage(200, 450, &tp[3]);
	putimage(200, 600, &tp[4]);

}
void gk::load() {
	loadimage(&tp[0], "./IMAGE/gq1.jpg");
	loadimage(&tp[1], "./IMAGE/gq2.jpg");
	loadimage(&tp[2], "./IMAGE/gq3.jpg");
	loadimage(&tp[3], "./IMAGE/gq4.jpg");
	loadimage(&tp[4], "./IMAGE/fh.jpg");
}
void gk::start() {
	BeginBatchDraw();
		while (1) {
			print();
			FlushBatchDraw();
			MOUSEMSG m = GetMouseMsg();
			if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 0 && m.y <= 100) {  gkk k4("./IMAGE/bki.jpg", 1); }
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 150 && m.y <= 250) { gkk k4("./IMAGE/bki.jpg", 2); }
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >=  300&& m.y <= 400) {gkk k4("./IMAGE/bki.jpg", 3); }
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 450 && m.y <= 550) {  gkk k4("./IMAGE/bki.jpg", 4);}
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 600 && m.y <= 700) {  return;}
		}
}