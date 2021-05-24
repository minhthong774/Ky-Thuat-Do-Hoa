#include <iostream>
#include <graphics.h>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>
#include <time.h>
#include "DescartesCoordinate.h"
#include "pixel.h"
#include "baitapNho.h"
#include "Shape.h"
#include "xuli.h"
#include "Button.h"
#include "Matrix.h"
#include "Human.h"
#include <map>

using namespace transformation;
using namespace shape;
void first_screen();

int x_coord = 0;
int y_coord = 0;
int x_prev,y_prev,x_curr,y_curr;
int draw = 0;

int mode=0;
std::vector<Button*> buttons;
std::vector<TextBox*> textBoxs;
int main(int argc, char** argv) {
	// now, you can run project
    initwindow(1920, 1280);           // init window graphics
    
	Button* button1 = new Button(50,20,200,60, "NET DUT");
	Button* button2 = new Button(50,60,200,100,"NET CHAM GACH");
	Button* button3 = new Button(50,100,200,140,"NET HAI CHAM GACH");
	Button* button4 = new Button(50,140,200,180, "MUI TEN");
	Button* button5 = new Button(50,180,200,220, "HINH CHU NHAT");
	Button* button6 = new Button(50,220,200,260, "CLEAR");
	Button* button7 = new Button(50,300,100,320, "PUT");
	Button* button8 = new Button(50,330,100,350, "X: ");
	Button* button9 = new Button(50,350,100,370, "Y: ");
	
	std::map<std::string,int> modes;
	modes.insert(std::pair<std::string,int>("NET DUT", 0));
	modes.insert(std::pair<std::string,int>("NET CHAM GACH", 1));
	modes.insert(std::pair<std::string,int>("NET HAI CHAM GACH", 2));
	modes.insert(std::pair<std::string,int>("MUI TEN", 3));
	modes.insert(std::pair<std::string,int>("HINH CHU NHAT", 4));
	modes.insert(std::pair<std::string,int>("CLEAR", 5));
	modes.insert(std::pair<std::string,int>("PUT", 6));
	modes.insert(std::pair<std::string,int>("X: ", 7));
	modes.insert(std::pair<std::string,int>("Y: ", 8));
	
	TextBox* textBoxx = new TextBox(110,330,150,350, "GET X");
	TextBox* textBoxy = new TextBox(110,350,150,370, "GET Y");
	
	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
	buttons.push_back(button5);
	buttons.push_back(button6);
	buttons.push_back(button7);
	buttons.push_back(button8);
	buttons.push_back(button9);
	textBoxs.push_back(textBoxx);
	textBoxs.push_back(textBoxy);
	
	first_screen();
	put_pixel(0,0);
	
	//testing
//	Vec4 a(5,7);
//	Matrix4x4 matrix1 = translate(-3,7);
//	Matrix4x4 matrix2 = matrix1*rotateZ(180*3.14/180);
//	a = a*matrix2;
//	std::cout<<round(a.x)<<"+++"<<round(a.y)<<std::endl;
//	Vec4 b(-34,-23);
//	Line::getInstance()->drawLine(a,b);
//	Circle circle(5,5,15);
//	circle.midPointCircleDraw();
//	Triangle triangle(14,10,-5,13,-2,-15);
//	triangle.draw();
	Human human;
	Matrix4x4 trans = rotateZ(3.14*90/180.0);
	Matrix4x4 trans1 = scale(2,2,1);
	human.Transformation(trans1);
	human.Draw();
	time_t timer;
	struct tm y2k = {0};
	double seconds,secondslast;
	
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	
	time(&timer);  /* get current time; same as: timer = time(NULL)  */
	
	secondslast = difftime(timer,mktime(&y2k));
	std::cout<<std::fixed<<seconds;
	int i =0;
//	while(true){
//		delay(20);
//		time(&timer);
//		seconds = difftime(timer,mktime(&y2k));
//		Matrix4x4 trans = translate(-1,0);
//		colorDraw = CYAN;
//		human.Draw();
//		colorDraw = RED;
//		human.Transformation(trans);
//		human.Draw();
//		secondslast = seconds;
//		std::cout<<seconds<<std::endl;
//		i++;
//		if(i==50){
//			i=0;
//			Matrix4x4 trans = translate(50,0);
//			colorDraw = CYAN;
//			human.Draw();
//			colorDraw = RED;
//			human.Transformation(trans);
//			human.Draw();
//		}
//	}
	//-----------------------------
	
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
					for(std::vector<Button*>::iterator it= buttons.begin(); it != buttons.end(); ++it){
						if((*it)->getChose()) {
							//draw tangle
							switch(modes[(*it)->getName()]) {
								case 0:draw_net_dut(x_prev, y_prev, x_curr, y_curr);
									break;
								case 1:draw_net_cham_gach(x_prev, y_prev, x_curr, y_curr);
									break;
								case 2:draw_net_hai_cham_gach(x_prev, y_prev, x_curr, y_curr);
									break;
								case 3:draw_arrow(x_prev, y_prev, x_curr, y_curr);
									break;
								case 4:draw_rectangle(x_prev, y_prev, x_curr, y_curr);
									break;
								case 5:
									break;
								case 6:
									break;
								default:
									break;
							}
							draw = 0;
							break;
						}
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
					if((*it)->getName() == "CLEAR"){
						first_screen();
						break;
					}
					if((*it)->getName() == "PUT"){
						put_pixel(x_coord, y_coord);
						break;
					}
				}else if((*it)->get_highlight()){
					(*it)->set_highlight(false);
					(*it)->setChose(false);
					(*it)->visible();
				}
			}
			for(std::vector<TextBox*>::iterator it=textBoxs.begin();it!=textBoxs.end();++it){
				if((*it)->is_in_range(x,y)){
					(*it)->action();
					if((*it)->getName() == "GET X"){
						cston((*it)->getText(), &x_coord);
					};
					if((*it)->getName() == "GET Y"){
						cston((*it)->getText(), &y_coord);
					};
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
	for(std::vector<Button*>::iterator it= buttons.begin(); it != buttons.end(); ++it){
		(*it)->visible();
	}
	for(std::vector<TextBox*>::iterator it=textBoxs.begin();it!=textBoxs.end();++it){
		(*it)->visible();
		(*it)->clear();
	}
}

