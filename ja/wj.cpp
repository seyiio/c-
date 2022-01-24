#include "wj.h"

wj::wj() :fj((WIDTH-100)/2,HEIGHT-100,100,100,5,5,1)/*初始化*/{
}
void wj::move() {
	if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && y > 0) {
		y -= speed;
	}if ((GetAsyncKeyState(VK_DOWN)
|| GetAsyncKeyState('S')) && y < HEIGHT - 100) {
		y += speed;
	}if ((GetAsyncKeyState(VK_LEFT)|| GetAsyncKeyState('A'))&&x>0) {
		x -= speed;
	}if ((GetAsyncKeyState(VK_RIGHT)|| GetAsyncKeyState('D'))&&x<WIDTH-100) {
		x += speed;
	}
}
bool wj::shoot() {
	static DWORD t1 = 0, t2 = 0;
	
	if (GetAsyncKeyState(VK_SPACE)&&t2-t1>400/*射击速度设置*/) {
		t1 = t2;
		return true;
	}
	else {
		t2 = GetTickCount();/*操作系统运行时间*/
		return false; }
}
void wj::ch(int n) {
	static DWORD t1 = 201, t2 = 0;
	t2 = GetTickCount();
	if (t2 - t1 > 200) {
		t1 = t2;
		health += n;
	}
	else {
		
		return ;
	}
}
bool wj:: bboom() {
	static DWORD t1 = 0, t2 = 0;
	if (GetAsyncKeyState('J') && t2 - t1 > 400) {
		t1 = t2;
		return true;
	}
	else {
		t2 = GetTickCount();
		return false;
	} 
}

