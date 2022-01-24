#include "zt.h"
zt::zt(){
}
void zt::load() {
	loadimage(&tp[0], "./IMAGE/fh.jpg");
	loadimage(&tp[1], "./IMAGE/jx.jpg");
}
void zt::print() {
	fillroundrect(100,100,500,700,5,5);
	putimage(200, 220, &tp[0]);
	putimage(200, 460, &tp[1]);
}
bool zt::start() {
	setlinecolor(YELLOW);   
	setfillcolor(BLUE);
	load();
	BeginBatchDraw();
	while (1) {
		print();
		FlushBatchDraw();
		MOUSEMSG m = GetMouseMsg();
		if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 220 && m.y <= 340) {
			return true;
		}
		else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 460 && m.y <= 580) {
			return false;
		}
	}
}