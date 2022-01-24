#include "startjm.h"

startjm::startjm() :jiemian("./IMAGE/bki.jpg") {
	load();
	start();
}
void startjm:: print() {
	putimage(0, 0, &background);
	putimage(200, 200, &tp[0]);
	putimage(200, 400, &tp[1]);
	putimage(200, 600, &tp[2]);

}
void startjm::load(){
	
		loadimage(&tp[1], "./IMAGE/phb.jpg");
		loadimage(&tp[2], "./IMAGE/tc.jpg");
		loadimage(&tp[0], "./IMAGE/ks.jpg");
	}
bool startjm::start(){
	BeginBatchDraw();
		while (1) {
			print();
			FlushBatchDraw();
			MOUSEMSG m = GetMouseMsg();
			if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 200 && m.y <= 300) {
				
				gkk i("./IMAGE/gki.jpg");//生成游戏画面的对象
				char n[11];
				InputBox(n, 11, "请输入你的名字" );//弹出输入窗口
				js jieshu(i.gets(),n);//生成结束画面的对象
		
			}
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 400 && m.y <= 500) {
				phb a;//生成排行榜的对象
				a.start();//生成画面
				
			}
			else if (m.mkLButton&&m.x >= 200 && m.x <= 400 && m.y >= 600 && m.y <= 700) {
				exit(0);
			}
			
		}EndBatchDraw();
}
