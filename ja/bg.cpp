#include "bg.h"

bg::bg(): character(rand() % 600, 0,50,50,1,3,0){
	id = rand() % 3;//�������һ��id
}
void bg::move() {
	y += speed;
}
int bg::gid() {
	return id;
}