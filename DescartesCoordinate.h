#ifndef __DescartesCoordinate.h
#define __DescartesCoordinate.h
#include "pixel.h"
#include "xuli.h"
void draw_triangle_direction(int x1, int y1, int x2, int y2, int x3, int y3){
	setcolor(1);
	setfillstyle(SOLID_FILL, BLUE);
	line(x1,y1,x2,y2);
	line(x1,y1,x3,y3);
	line(x2,y2,x3,y3);
	putpixel(x1,y1,BLUE);
	putpixel(x2,y2,BLUE);
	putpixel(x3,y3,BLUE);
	floodfill(((x1+x3)/2+x2)/2, ((y1+y3)/2+y2)/2, BLUE);
	reset_color();
}

void draw_xOy(){
	//draw grid pixel			
	for(int x = min;x<=max;x++){
		for(int y = min;y<=max;y++){
			put_pixel_grid(to_screen_coord_x(x),to_screen_coord_y(y));
		}
	}
	//draw axis
	setcolor(1);
	//x axis
	line(x_offset-10, 5*max+ y_offset+3, x_offset+max*5*2+10, 5*max+ y_offset+3);
	//y axis
	line(5*max+ x_offset+3, y_offset-10, 5*max+x_offset+3, y_offset+max*5*2+10);
	//left
	draw_triangle_direction(x_offset-25,5*max+ y_offset,
							x_offset-10,5*max+ y_offset-15,
							x_offset-10,5*max+ y_offset+15);
	//top
	draw_triangle_direction(5*max+ x_offset-15, y_offset-10,
							5*max+ x_offset+15, y_offset-10,
							5*max+ x_offset, y_offset-25);
	//right
	draw_triangle_direction(x_offset+max*5*2+25, 5*max+ y_offset,
							x_offset+max*5*2+10, 5*max+ y_offset-15,
							x_offset+max*5*2+10, 5*max+ y_offset+15);	
	//bottom
	draw_triangle_direction(5*max+x_offset-15, y_offset+max*5*2+10,
							5*max+x_offset+15, y_offset+max*5*2+10,
							5*max+x_offset, y_offset+max*5*2+25);
	reset_color();
	outtextxy(x_offset+max*5*2+10, 5*max+ y_offset+20,"X");
	outtextxy(5*max+ x_offset + 20, y_offset-10,"Y");
	outtextxy(5*max+ x_offset + 15, 5*max+ y_offset + 5, "O");
}

void drawOxyz(){
	draw_xOy();
	setcolor(1);
	line(x_offset-10 +5, y_offset+max*5*2+10, x_offset+max*5*2+10 +5 , y_offset-10);
	draw_triangle_direction(x_offset+max*5*2+10 +5 , y_offset-10,
							x_offset+max*5*2+10 +5 -10 , y_offset-10,
							x_offset+max*5*2+10 +5 , y_offset-10 + 10);
	outtextxy(x_offset+max*5*2+10 +5 , y_offset-10+20,"Z");
	reset_color();
}

void draw_xOy_without_xOy(){			
	for(int x = min;x<=max;x++){
		for(int y = min;y<=max;y++){
			put_pixel_grid(to_screen_coord_x(x),to_screen_coord_y(y));
		}
	}
	setcolor(1);
	reset_color();
}


bool is_in_range(int x, int y){
	return (x>x_offset && x<5*max*2+x_offset)&&(y > y_offset && y<5*max*2+y_offset)?true:false;
}
#endif
