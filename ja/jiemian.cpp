#include "jiemian.h"

jiemian::jiemian(LPCTSTR path){
		initgraph(WIDTH, HEIGHT);
		loadimage(&background, path);
		putimage(0, 0, &background);
		
}
jiemian::jiemian() {
}
