#include "zd.h"

zd::zd(int x, int y, int health, int speed,int d):character(x, y,5,5, health, speed,d) {

}	
 void  zd::move() { 
		y-=speed;
		if (y < 0) {
			live = false;
		}
}


