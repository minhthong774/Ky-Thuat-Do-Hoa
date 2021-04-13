#include <iostream>
#include <graphics.h>
#include <string>
#include <math.h>
#include <vector>
#include "xuli.h"
#include "Button.h"
//abcdef
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void draw_xOy();
void draw_triangle_direction(int x1, int y1, int x2, int y2, int x3, int y3);
void put_pixel(int x, int y);
void put_pixel_grid(int x, int y);
void put_pixel_screen(int x, int y);
bool is_in_range(int x, int y);
void enter_coords_x();
void enter_coords_y();
void first_screen();
bool functionReturnTrue(int a);
void draw_line(int x1,int y1,int x2,int y2, bool (*checkVisible)(int));
void draw_line(int x1,int y1,int x2,int y2);
bool checkVisibleNetDut(int count);
bool checkVisibleNetChamGach(int count);
bool checkVisibleNetHaiChamGach(int count);
void draw_net_dut(int x1,int y1,int x2,int y2);
void draw_net_cham_gach(int x1,int y1,int x2,int y2);
void draw_net_hai_cham_gach(int x1,int y1,int x2,int y2);
void draw_arrow(int x1,int y1,int x2,int y2);
void draw_rectangle(int x1,int y1,int x2,int y2);

int x_text=0;
int y_text=0;
int x_coord = 0;
int y_coord = 0;
int x_prev,y_prev,x_curr,y_curr;
int draw = 0;

int mode=0;

int main(int argc, char** argv) {
	// now, you can run project
    initwindow(1280, 760);           // init window graphics
    first_screen();
    
	ButtonDraw* button1 = new ButtonDraw(50,20,200,60, "NET DUT");
	button1->setFunctionDraw(&draw_net_dut);
	ButtonDraw* button2 = new ButtonDraw(50,60,200,100,"NET CHAM GACH");
	button2->setFunctionDraw(&draw_net_cham_gach);
	ButtonDraw* button3 = new ButtonDraw(50,100,200,140,"NET HAI CHAM GACH");
	button3->setFunctionDraw(&draw_net_hai_cham_gach);
	ButtonDraw* button4 = new ButtonDraw(50,140,200,180, "MUI TEN");
	button4->setFunctionDraw(&draw_arrow);
	ButtonDraw* button5 = new ButtonDraw(50,180,200,220, "HINH CHU NHAT");
	button5->setFunctionDraw(&draw_rectangle);
	std::vector<ButtonDraw*> buttonDraws;
	buttonDraws.push_back(button1);
	buttonDraws.push_back(button2);
	buttonDraws.push_back(button3);
	buttonDraws.push_back(button4);
	buttonDraws.push_back(button5);
	
	Button* button6 = new Button(50,220,200,260, "CLEAR");
	Button* button7 = new Button(50,300,100,320, "PUT");
	Button* button8 = new Button(50,330,100,350, "X: ");
	Button* button9 = new Button(50,350,100,370, "Y: ");
	std::vector<Button*> buttons;
	
	buttons.push_back(button6);
	buttons.push_back(button7);
	buttons.push_back(button8);
	buttons.push_back(button9);
	for(std::vector<ButtonDraw*>::iterator it = buttonDraws.begin(); it != buttonDraws.end(); ++it){
		(*it)->visible();
	}
	
 	put_pixel(0,0);
	while(true){
 		delay(0.0001);
 		if(ismouseclick(WM_LBUTTONDOWN)){
 			int x,y;
 			getmouseclick(WM_LBUTTONDOWN,x,y);
 			//put pixel bang click chuot
 			if(is_in_range(x,y)){
				put_pixel_screen(x,y);
				x_prev = x_curr;
				y_prev = y_curr;
				x_curr = to_descartes_coord_x(x);
				y_curr = to_descartes_coord_y(y);
				draw++;
				if(draw == 2){
					for(std::vector<ButtonDraw*>::iterator it= buttonDraws.begin(); it != buttonDraws.end(); ++it){
						if((*it)->getChose()) (*it)->draw(x_prev,y_prev,x_curr,y_curr);
						draw = 0;
					}
					draw = 0;
				}
				continue;
			}
			for(std::vector<Button*>::iterator it= buttons.begin(); it != buttons.end(); ++it){
				if((*it)->is_in_range(x,y)){
					(*it)->set_highlight(true);
					(*it)->visible();
					(*it)->setChose(true);
				}else if((*it)->get_highlight()){
					(*it)->set_highlight(false);
					(*it)->setChose(false);
					(*it)->visible();
				}
			}
		}
	}
 	
    while(!kbhit()) delay(1);       // pause screen
    return 0;
}

void first_screen(){
	reset_color();                 // set background
    cleardevice();               // set text color
 	draw_xOy();
	
}

void draw_xOy(){
	//draw grid pixel			
	for(int x = -50;x<=max;x++){
		for(int y = -50;y<=max;y++){
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

bool is_in_range(int x, int y){
	return (x>x_offset && x<5*max*2+x_offset)&&(y > y_offset && y<5*max*2+y_offset)?true:false;
}

void enter_coords_x(){
	x_coord=process_coord();
}

void enter_coords_y(){
	y_coord=process_coord();
}

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


