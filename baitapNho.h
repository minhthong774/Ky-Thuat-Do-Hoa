#ifndef __baitapNho.h
#define __baitapNho.h
void draw_line(int x1,int y1,int x2,int y2, bool (*checkVisible)(int)){
	int dx = x1 > x2 ? x1 - x2 : x2 - x1;
	int dy = y2 > y1 ? y2 - y1 : y1 -y2;
	
	int count = 0;
	
	if(dx > dy) {
		int p = 2*dy - dx;
		int x = x1;
		int y = y1;
		put_pixel(x, y);
		
		if(x > x2) {
			while(x > x2) {
			if(p < 0) {
				p = p + 2*dy;
			} else {
				p = p + 2*dy - 2*dx;
				if(y <= y2) {
					y++;
				} else {
					y--;
				}
			}
			x--;
			count++;
			if(checkVisible(count))put_pixel(x, y);
			}
		} else if( x < x2) {
				while(x < x2) {
			if(p < 0) {
				p = p + 2*dy;
				y =y ;
			} else {
				p = p + 2*dy - 2*dx;
				if(y >= y2) {
					y--;
				} else {
					y++;
				}
			}
			x++;
			count++;
			if(checkVisible(count))put_pixel(x, y);
			}
		}
	} else {
		int p = 2*dx - dy;
		
		int x = x1;
		int y = y1;
		
		put_pixel(x, y);
		
		if(y > y2) {
			while(y > y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x <= x2) {
					x++;
				} else {
					x--;
				}
			}
			y--;
			count++;
			if(checkVisible(count))put_pixel(x, y);
			}
		} else if( y < y2) {
				while(y < y2) {
			if(p < 0) {
				p = p + 2*dx;
			} else {
				p = p + 2*dx - 2*dy;
				if(x >= x2) {
					x--;
				} else {
					x++;
				}
			}
			y++;
			count++;
			if(checkVisible(count))put_pixel(x, y);
			}
		}
	}
}

bool functionReturnTrue(int a){
	return true;
}

void draw_line(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x2,y2,&functionReturnTrue);
}

bool checkVisibleNetDut(int count){
	return count %12 != 11 && count % 12 != 10;
}

bool checkVisibleNetChamGach(int count){
	return count %12 != 11 && count % 12 != 9;
}

bool checkVisibleNetHaiChamGach(int count){
	return count %12 != 11 && count % 12 != 9 && count % 12 != 7;
}

void draw_net_dut(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x2,y2,&checkVisibleNetDut);
}
void draw_net_cham_gach(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x2,y2,&checkVisibleNetChamGach);
}
void draw_net_hai_cham_gach(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x2,y2,&checkVisibleNetHaiChamGach);
}

void draw_arrow(int start_x, int start_y, int end_x, int end_y){
	int arrow_lenght_ = 10;
	double arrow_degrees_ = 0.5;
	double x1, y1 , x2,y2;
    double angle = atan2 (end_y - start_y, end_x - start_x) + M_PI;
 		
    x1 = end_x + arrow_lenght_ * cos(angle - arrow_degrees_);
    y1 = end_y + arrow_lenght_ * sin(angle - arrow_degrees_);
    x2 = end_x + arrow_lenght_ * cos(angle + arrow_degrees_);
    y2 = end_y + arrow_lenght_ * sin(angle + arrow_degrees_);
    draw_line(end_x,end_y,x1,y1);
    draw_line(end_x,end_y,x2,y2);
    draw_line(x1,y1,x2,y2);
    draw_line(start_x,start_y,end_x,end_y);
}

void draw_rectangle(int x1,int y1,int x2,int y2){
	draw_line(x1,y1,x1,y2);
	draw_line(x1,y1,x2,y1);
	draw_line(x2,y2,x1,y2);
	draw_line(x2,y2,x2,y1);
}
#endif
