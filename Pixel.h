#ifndef __Pixel.h
#define __Pixel.h
#include"xuli.h"
void put_pixel_grid(int x, int y){
	x=(x-x_offset)/5*5;
	y=(y-y_offset)/5*5;
	setcolor(CYAN);
	setfillstyle(SOLID_FILL, CYAN);
	rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
	floodfill(x+2+x_offset,y+2+y_offset,CYAN);													
	reset_color();
}

void put_pixel_screen(int x, int y){
	x=(x-x_offset)/5*5;
	y=(y-y_offset)/5*5;
	setcolor(RED);
	setfillstyle(SOLID_FILL, RED);
	rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
	floodfill(x+2+x_offset,y+2+y_offset,RED);													
	reset_color();
}

void put_pixel(int x, int y){
	put_pixel_screen(to_screen_coord_x(x), to_screen_coord_y(y));
}
#endif
