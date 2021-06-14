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

bool is_in_range2(int x, int y){
	return (x>=x_offset && x<=5*max*2+x_offset)&&(y >= y_offset && y<=5*max*2+y_offset)?true:false;
}

void put_pixel_screen(int x, int y){
	if(is_in_range2(x,y)) {
		x=(x-x_offset)/5*5;
		y=(y-y_offset)/5*5;
		setcolor(colorDraw);
		setfillstyle(SOLID_FILL, colorDraw);
		rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
		floodfill(x+2+x_offset,y+2+y_offset,colorDraw);													
		reset_color();
	}
}

void put_pixel_screen2(int x, int y){
	if(is_in_range2(x,y)) {
		x=(x-x_offset)/5*5;
		y=(y-y_offset)/5*5;
		setcolor(CYAN);
		setfillstyle(SOLID_FILL, CYAN);
		rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
		floodfill(x+2+x_offset,y+2+y_offset,CYAN);													
		reset_color();
	}
}

void put_pixel_screen3(int x, int y, int color){
	if(is_in_range2(x,y)) {
		x=(x-x_offset)/5*5;
		y=(y-y_offset)/5*5;
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
		floodfill(x+2+x_offset,y+2+y_offset,color);													
		reset_color();
	}
}

void put_pixel_screen4(int x, int y, int color){
		x=(x-x_offset)/5*5;
		y=(y-y_offset)/5*5;
		setcolor(color);
		setfillstyle(SOLID_FILL, color);
		rectangle(x+1+x_offset,y+1+y_offset,x+4+x_offset,y+4+y_offset);
		floodfill(x+2+x_offset,y+2+y_offset,color);													
		reset_color();
}

void put_pixel(int x, int y){
	put_pixel_screen(to_screen_coord_x(x), to_screen_coord_y(y));
}

void put_pixel4(int x, int y, int color){
	put_pixel_screen4(to_screen_coord_x(x), to_screen_coord_y(y), color);
}

void put_pixel2(int x, int y){
	put_pixel_screen2(to_screen_coord_x(x), to_screen_coord_y(y));
}

void put_pixel3(int x, int y, int color){
	put_pixel_screen3(to_screen_coord_x(x), to_screen_coord_y(y), color);
}
#endif
