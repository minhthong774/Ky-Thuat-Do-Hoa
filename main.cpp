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
#include "Car.h"
#include "Fence.h"
#include "Tree.h"
#include "Human.h"
#include "Galaxy.h"
#include "3d_DinhMinhThong.h"
#include <map>
using namespace transformation;
using namespace shape;
void first_screen();
void first_screen_2D_mode_auto();
void giaoThong();
void hienThiThongTinToaDo(Car car, Tree tree);
void hieuUngBanhXeQuay(Car car, bool after_rotate);
void giaoThongThuCong(Matrix4x4 maTranBienDoi);
void giaoThongThuCong();

int x_coord = 0;
int y_coord = 0;
int x_translate = 0;
int y_translate = 0;
float x_scale = 0;
float y_scale = 0;
int gocQuay = 0;
int xDXD = 0;
int yDXD = 0;
int x_prev,y_prev,x_curr,y_curr;
int draw = 0;

Matrix4x4 maTranDichChuyenY = translate(0, 20);

int mode=0;
std::vector<Button*> buttons;
std::vector<TextBox*> textBoxs;
bool _3d = false;
std::vector<Button*> buttons3d;
std::vector<TextBox*> textBoxs3d;
int daihop, ronghop, caohop;
int caotru, bankinhtru;
int xpos, ypos, zpos;
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
	
	Button* button10 = new Button(50,400,200,440, "GIAO THONG");
	Button* button11 = new Button(50,440,200,480, "THU CONG");
	Button* button12 = new Button(50,480,200,520, "DOI XUNG OX");
	Button* button13 = new Button(50,520,200,560, "DOI XUNG OY");
	Button* button14 = new Button(50,560,200,600, "DOI XUNG O");
	Button* button15 = new Button(50,600,200,640, "TINH TIEN");
	Button* button16 = new Button(50,640,200,680, "BIEN DANG");
	Button* button17 = new Button(50,680,200,720, "QUAY");
	Button* button17_1 = new Button(50,720,200,760, "DOI XUNG DIEM");
	Button* button18 = new Button(250,20,450,60, "3D");
	Button* button19 = new Button(250,60,450,100, "HE MAT TROI");
	Button* button20 = new Button(50,100,200,140, "HINH HOP");
	Button* button22 = new Button(50,260,200,300, "HINH TRU");
	Button* button23 = new Button(50,20,200,60, "2D");
	Button* button24 = new Button(50,370,200,410, "CLEAR");
	
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
	
	TextBox* textBoxTranslatex = new TextBox(210,610,250,630, "GET X TRANSLATE");
	TextBox* textBoxTranslatey = new TextBox(260,610,300,630, "GET Y TRANSLATE");
	
	TextBox* textBoxScalex = new TextBox(210,650,250,670, "GET X SCALE");
	TextBox* textBoxScaley = new TextBox(260,650,300,670, "GET Y SCALE");
	
	TextBox* textBoxRotateAngle = new TextBox(210,690,250,710, "GET ANGLE ROTATE");
	
	TextBox* textBoxDoiXungDiemx = new TextBox(210,730,250,750, "GET X DXD");
	TextBox* textBoxDoiXungDiemy = new TextBox(260,730,300,750, "GET Y DXD");
	
	TextBox* textBoxChieuDaiHinhHop = new TextBox(100,150,200,170, "CHIEU DAI HINH HOP");
	TextBox* textBoxChieuRongHinhHop = new TextBox(100,180,200,200, "CHIEU RONG HINH HOP");
	TextBox* textBoxChieuCaoHinhHop = new TextBox(100,210,200,230, "CHIEU CAO HINH HOP");
	
	TextBox* textBox_xpos = new TextBox(250,50,350,70, "xpos");
	TextBox* textBox_ypos = new TextBox(250,80,350,100, "ypos");
	TextBox* textBox_zpos = new TextBox(250,110,350,130, "zpos");
	
	TextBox* textBoxChieuCaoHinhTru = new TextBox(100,310,200,330, "CHIEU CAO HINH TRU");
	TextBox* textBoxBanKinhHinhTru = new TextBox(100,340,200,360, "BAN KINH HINH TRU");
	
	buttons.push_back(button1);
	buttons.push_back(button2);
	buttons.push_back(button3);
	buttons.push_back(button4);
	buttons.push_back(button5);
	buttons.push_back(button6);
	buttons.push_back(button7);
	buttons.push_back(button8);
	buttons.push_back(button9);
	buttons.push_back(button10);
	buttons.push_back(button11);
	buttons.push_back(button12);
	buttons.push_back(button13);
	buttons.push_back(button14);
	buttons.push_back(button15);
	buttons.push_back(button16);
	buttons.push_back(button17);
	buttons.push_back(button17_1);
	buttons.push_back(button18);
	buttons.push_back(button19);
	
	buttons3d.push_back(button20);
	buttons3d.push_back(button22);
	buttons3d.push_back(button23);
	buttons3d.push_back(button24);
	
	textBoxs.push_back(textBoxx);
	textBoxs.push_back(textBoxy);
	
	textBoxs.push_back(textBoxTranslatex);
	textBoxs.push_back(textBoxTranslatey);
	
//	textBoxs.push_back(textBoxScalex);
//	textBoxs.push_back(textBoxScaley);
	
	textBoxs.push_back(textBoxRotateAngle);
	
	textBoxs.push_back(textBoxDoiXungDiemx);
	textBoxs.push_back(textBoxDoiXungDiemy);
	
	textBoxs3d.push_back(textBoxChieuDaiHinhHop);
	textBoxs3d.push_back(textBoxChieuRongHinhHop);
	textBoxs3d.push_back(textBoxChieuCaoHinhHop);
	textBoxs3d.push_back(textBoxChieuCaoHinhTru);
	textBoxs3d.push_back(textBoxBanKinhHinhTru);
	textBoxs3d.push_back(textBox_xpos);
	textBoxs3d.push_back(textBox_ypos);
	textBoxs3d.push_back(textBox_zpos);
	
	first_screen();

	//-----------------------------
	
	while(true){
 		delay(0.0001);
 		if(ismouseclick(WM_LBUTTONDOWN)){
 			int x,y;
 			getmouseclick(WM_LBUTTONDOWN,x,y);
 			//put pixel bang click chuot
 			if(!_3d){
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
					if((*it)->getName() == "GIAO THONG"){
						giaoThong();
						break;
					}
					if((*it)->getName() == "HE MAT TROI"){									
						solarSystem(200, 100);
						first_screen();
						break;
					}
					if((*it)->getName() == "THU CONG"){
						giaoThongThuCong();
						break;
					}
					if((*it)->getName() == "DOI XUNG OX"){
						Matrix4x4 doiXungOx = scale(1, -1, 1);
						giaoThongThuCong(doiXungOx);
						break;
					}
					if((*it)->getName() == "DOI XUNG OY"){
						Matrix4x4 doiXungOy = scale(-1, 1, 1);
						giaoThongThuCong(doiXungOy);
						break;
					}
					if((*it)->getName() == "DOI XUNG O"){
						Matrix4x4 doiXungO = scale(-1, -1, -1);
						giaoThongThuCong(doiXungO);
						break;
					}
					if((*it)->getName() == "TINH TIEN"){
						Matrix4x4 tinhTienX = translate(x_translate, y_translate);
						giaoThongThuCong(tinhTienX);
						break;
					}
					if((*it)->getName() == "BIEN DANG"){
						first_screen(); 
						Car car1;
						car1.Transformation(maTranDichChuyenY);
						car1.Draw();
						
						Matrix4x4 bienDangHeSoLonHon1 = scale(2, 2);
						Matrix4x4 bienDangHeSoNhoHon1 = scale(0.6, 0.6);
						Matrix4x4 dichChuyenX40Y40 = translate(40, -40);
						Matrix4x4 dichChuyenX60 = translate(60, 0);
						
//						float x_scale_float = static_cast<float>(x_scale);
//						float y_scale_float = static_cast<float>(y_scale);
						
//						std::cout<<x_scale_float;
//						std::cout<<x_scale_float;
						
						Car car2(car1);
						car2.Transformation(dichChuyenX40Y40);
						car2.Transformation(bienDangHeSoLonHon1);
						car2.updateRadiusForWheel(2);
						car2.Draw();
											
						Car car3(car1);
						car3.Transformation(dichChuyenX60);
						car3.Transformation(bienDangHeSoNhoHon1);
						car3.updateRadiusForWheel(0.6);			
						car3.Draw();
						
//						Matrix4x4 bienDang = scale(x_scale_float, y_scale_float);
//						Matrix4x4 bienDang = scale(x_scale, y_scale);
//						Car car4(car1);
//						car4.Transformation(dichChuyenX40Y40);
//						car4.Transformation(bienDang);
//						car4.updateRadiusForWheel(y_scale);
//						car4.Draw();
						break;
					}
					if((*it)->getName() == "QUAY"){
						Matrix4x4 quayTamO = rotateZ(gocQuay*3.14/180.0);
						giaoThongThuCong(quayTamO);
						break;
					}
					if((*it)->getName() == "3D"){
						_3d=true;
						first_screen();
						break;
					}
					if((*it)->getName() == "DOI XUNG DIEM"){
						Matrix4x4 matrixDX = translate(-xDXD,-yDXD)*scale(-1,-1,-1)*translate(xDXD,yDXD);
						giaoThongThuCong(matrixDX);
						break;
					}
					//goi cac ham ve 2D o day
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
					if((*it)->getName() == "GET X TRANSLATE"){
						cston((*it)->getText(), &x_translate);
					};
					if((*it)->getName() == "GET Y TRANSLATE"){
						cston((*it)->getText(), &y_translate);
					};
					if((*it)->getName() == "GET X SCALE"){
						cston2((*it)->getText(), &x_scale);
					};
					if((*it)->getName() == "GET Y SCALE"){
						cston2((*it)->getText(), &y_scale);
					};
					if((*it)->getName() == "GET ANGLE ROTATE"){
						cston((*it)->getText(), &gocQuay);
					};
					if((*it)->getName() == "GET X DXD"){
						cston((*it)->getText(), &xDXD);
					};
					if((*it)->getName() == "GET Y DXD"){
						cston((*it)->getText(), &yDXD);
					};
				}
			}
		}
		else{
			for(std::vector<Button*>::iterator it= buttons3d.begin(); it != buttons3d.end(); ++it){
				if((*it)->is_in_range(x,y)){
					(*it)->set_highlight(true);
					(*it)->visible();
					(*it)->setChose(true);
					if((*it)->getName() == "2D"){
						_3d=false;
						first_screen();
						break;
					}
					if((*it)->getName() == "HINH HOP"){
						drawRectangular(Vec4(xpos,ypos,zpos), daihop, ronghop, caohop);
						break;
					}
					if((*it)->getName() == "HINH TRU"){
						drawCylinder(Vec4(xpos,ypos,zpos), caotru, bankinhtru);
						break;
					}
					if((*it)->getName() == "CLEAR"){
						first_screen();
						break;
					}
				}else if((*it)->get_highlight()){
					(*it)->set_highlight(false);
					(*it)->setChose(false);
					(*it)->visible();
				}
			}
			for(std::vector<TextBox*>::iterator it=textBoxs3d.begin();it!=textBoxs3d.end();++it){
				if((*it)->is_in_range(x,y)){
					(*it)->action();
					if((*it)->getName() == "CHIEU DAI HINH HOP"){
						cston((*it)->getText(), &daihop);
					};
					if((*it)->getName() == "CHIEU RONG HINH HOP"){
						cston((*it)->getText(), &ronghop);
					};
					if((*it)->getName() == "CHIEU CAO HINH HOP"){
						cston((*it)->getText(), &caohop);
					};
					if((*it)->getName() == "CHIEU CAO HINH TRU"){
						cston((*it)->getText(), &caotru);
					};
					if((*it)->getName() == "BAN KINH HINH TRU"){
						cston((*it)->getText(), &bankinhtru);
					};
					if((*it)->getName() == "xpos"){
						cston((*it)->getText(), &xpos);
					};
					if((*it)->getName() == "ypos"){
						cston((*it)->getText(), &ypos);
					};
					if((*it)->getName() == "zpos"){
						cston((*it)->getText(), &zpos);
					};
				}
			}
		}
	}}
 	
    while(!kbhit()) delay(1);       // pause screen
    return 0;
}

void first_screen(){
	reset_color();                 // set background
    cleardevice();               // set text color
    if(!_3d){
	 	draw_xOy();
		for(std::vector<Button*>::iterator it= buttons.begin(); it != buttons.end(); ++it){
			(*it)->visible();
		}
		for(std::vector<TextBox*>::iterator it=textBoxs.begin();it!=textBoxs.end();++it){
			(*it)->clear();
			(*it)->visible();
		}
	}
	else{
		drawOxyz();
		for(std::vector<Button*>::iterator it= buttons3d.begin(); it != buttons3d.end(); ++it){
			(*it)->visible();
		}
		for(std::vector<TextBox*>::iterator it=textBoxs3d.begin();it!=textBoxs3d.end();++it){
			(*it)->clear();
			(*it)->visible();
		}
		outtextxy(250,20,"Position:");
		outtextxy(50,150,"D:");
		outtextxy(50,180,"R:");
		outtextxy(50,210,"C:");
		outtextxy(50,310,"C:");
		outtextxy(50,340,"BK:");
	}

}

void first_screen_2D_mode_auto(){
	reset_color();                 // set background
    cleardevice();               // set text color
	draw_xOy_without_xOy();
	for(std::vector<Button*>::iterator it= buttons.begin(); it != buttons.end(); ++it){
		(*it)->visible();
	}
	for(std::vector<TextBox*>::iterator it=textBoxs.begin();it!=textBoxs.end();++it){
		(*it)->clear();
		(*it)->visible();
	}
}

void giaoThongThuCong() {
	first_screen(); 
	
	Car car1;
	car1.Transformation(maTranDichChuyenY);
	car1.Draw();
}

void giaoThongThuCong(Matrix4x4 maTranBienDoi) {
	first_screen(); 
	
	Car car1;
	car1.Transformation(maTranDichChuyenY);
	car1.Draw();

	Car car2(car1);
	car2.Transformation(maTranBienDoi);
	car2.Draw();
}

void giaoThong() {
	first_screen_2D_mode_auto();
	
	time_t timer;
	struct tm y2k = {0};
	double seconds,secondslast;
	
	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
	
	// ============================== TREE =============================================
	Tree tree1;
	Tree tree2(20, 51, 20, 26, 25, 26, 25, 51);
	Tree tree3(-25, 51, -25, 26, -20, 26, -20, 51);
	Tree tree4(110, 51, 110, 26, 115, 26, 115, 51);
	Tree tree5(140, 51, 140, 26, 145, 26, 145, 51);
		
	Matrix4x4 treeTrans = translate(-2, 0);
	Matrix4x4 translateY2 = translate(0, 11);
	Matrix4x4 translateY3 = translate(0,6);	
	Matrix4x4 treeShrink2 = scale(0.8, 0.8);

	Matrix4x4 treeShrink3 = scale(0.6, 0.6);
	Matrix4x4 translate2 = translate(20,7);
	Matrix4x4 carShrink2 = scale(0.7, 0.7);
	
	tree2.Transformation(treeShrink3);
	tree2.Transformation(translateY2);
	tree2.updateRadiusForCircle(0.6);
		
	tree3.Transformation(treeShrink2);	
	tree3.Transformation(translateY3);
	tree3.updateRadiusForCircle(0.8);

	tree5.Transformation(treeShrink3);
	tree5.Transformation(translateY2);
	tree5.updateRadiusForCircle(0.6);

	tree1.Draw2();
	tree2.Draw();
	tree3.Draw();
	tree4.Draw();
	tree5.Draw();
	
// ============================== END OF TREE =============================================

// ============================== FENCE ============================================	

	// Draw Fence		
	Matrix4x4 fenceTranslate;
	for(int i = 0; i < 80; i+=7) {
		Fence *fence = new Fence();
		fenceTranslate = translate(-75 + i,-45);
		fence->Transformation(fenceTranslate);
		fence->Draw();
	}

// ============================= END OF FENCE ============================================	


// =============================  LINE  ============================================
	draw_line(-70 , 25 , 70, 25);
	draw_line(-70, -25 , 20, -25);
	draw_line(20, -25 , 20, -40);
	draw_line(-70, -40 , 20, -40);
// =============================  END OF  LINE  ============================================
	
	
// ============================== CAR ==============================================	

	Car car1;
	Car car2;
	Car car3; 
	
	Matrix4x4 car3Trans = translate(-80, -15);
	Matrix4x4 doiXungOy = scale(-1, 1, 1);
	Matrix4x4 carTrans;
	Matrix4x4 scale1;
	Matrix4x4 rotate;
	Matrix4x4 transY;
	Matrix4x4 maxSpeed;
	Matrix4x4 dichuyenNguocLai;
	
	car2.Transformation(carShrink2);
	car2.updateRadiusForWheel(0.8);
	car2.Transformation(doiXungOy);
	car2.Transformation(translate2);

	car3.Transformation(car3Trans);
	
	car1.Draw();
//	car2.Draw();

	float scaleFactor = 1;
	int yy = 0, x = 0;	
	bool after_rotate;
	//============================= THONG TIN TOA DO BAN DAU ====================================
	hienThiThongTinToaDo(car1, tree1);
	//===========================================================================================
	
	while((!kbhit())&&!ismouseclick(WM_LBUTTONDOWN)) {
	
		delay(1);
		time(&timer);
		seconds = difftime(timer,mktime(&y2k));		
		
		carTrans = translate(2,0);
		dichuyenNguocLai = translate(-2,0);
		maxSpeed = translate(10, 0);
		after_rotate = false;
		
		if(x > 30) {
			carTrans = translate(-3,0);
			after_rotate = true;
		}	
		if(x == 70) {
			first_screen();
			break;
		}	
			
		if(x == 8) {
			colorDraw = CYAN;
			car2.Draw();
			colorDraw = RED;
			car2.Transformation(dichuyenNguocLai);	
			car2.Draw();
			
			for(int i = 0; i < 10; i ++) {
				scale1 = scale(scaleFactor, scaleFactor);
				transY = translate(0,-2);
				colorDraw = CYAN;
				car1.Draw();
				colorDraw = RED;
									
				scaleFactor -= 0.008;
				car1.Transformation(scale1);
				car1.updateRadiusForWheel(0.0008);						
				car1.Transformation(transY);
				car1.Draw();					
			}	
		}
		
		if(x == 27) {
			for(int i = 0; i < 10; i ++) {
				delay(1);
				scale1 = scale(1 + 0.04,1 + 0.04);
				transY = translate(0,1);
				colorDraw = CYAN;
				car1.Draw();
				colorDraw = RED;
									
				scaleFactor += 0.008;
				car1.Transformation(scale1);
				car1.updateRadiusForWheel(-0.0008);						
				car1.Transformation(transY);
				car1.Draw();
			}	
		}
		
		if(x == 30) {				
			Matrix4x4 trans2 = translate(3,2);
			Matrix4x4 carShrink = scale(0.8, 0.8);
			
			colorDraw = CYAN;
			car1.Draw();
			colorDraw = RED;
			car1.Transformation(carShrink);
			car1.updateRadiusForWheel(0.8);
			car1.Draw();
				
			for(int i = 0; i < 14; i++) {
				delay(1);
				rotate = rotateZ(-i*3.14/180.0);
				colorDraw = CYAN;
				car1.Draw();
				car2.Draw();
				colorDraw = RED;
				
				car1.Transformation(rotate);
				car1.Transformation(trans2);
				car1.Draw();		
				
				car2.Transformation(dichuyenNguocLai);	
				car2.Draw();
				
				hieuUngBanhXeQuay(car1, false);	
				hienThiThongTinToaDo(car1, tree1);			
			}
			Matrix4x4 quay90Do = rotateZ(-90*3.14/180.0);
			Matrix4x4 getBackToDesiredLocation = translate(80, -95);
			
			colorDraw = CYAN;
			car1.Draw();
			colorDraw = RED;
			car1.Transformation(doiXungOy);
			car1.Transformation(quay90Do);
			car1.Transformation(getBackToDesiredLocation);
			car1.Draw();
			car3.Draw();
			
			carTrans = translate(-3, 0);
			after_rotate = true;
		}	
		
		if(x >32) {
			colorDraw = CYAN;
			car3.Draw();
			colorDraw = RED;
			car3.Transformation(maxSpeed);
			car3.Draw();
		}
		
		colorDraw = CYAN;
		tree1.Draw2();
		tree2.Draw();
		tree3.Draw();
		tree4.Draw();
		tree5.Draw();
		car1.Draw();
		car2.Draw();
		colorDraw = RED;
		tree1.Transformation(treeTrans);	
		tree2.Transformation(treeTrans);
		tree3.Transformation(treeTrans);
		tree4.Transformation(treeTrans);			
		tree5.Transformation(treeTrans);
		car1.Transformation(carTrans);
		car2.Transformation(dichuyenNguocLai);	
		tree1.Draw2();
		tree2.Draw();
		tree3.Draw();
		tree4.Draw();
		tree5.Draw();
		car1.Draw();
		car2.Draw();
		
		if(!after_rotate) {
			hieuUngBanhXeQuay(car1, false);
		} else {
			hieuUngBanhXeQuay(car1, true);
		}
	
		secondslast = seconds;
		x++;	
		
//============================================ HIEN THI THONG TIN TOA DO =================================================== 
	hienThiThongTinToaDo(car1, tree1);
	}
}

void hieuUngBanhXeQuay(Car car1, bool after_rotate) {
		int centerX_w1, centerX_w2, centerY_w1, centerY_w2, radius_w1, radius_w2;
		centerX_w1 = car1.getWheel1().getCenter().x;
		centerX_w2 = car1.getWheel2().getCenter().x;
		centerY_w1 = car1.getWheel1().getCenter().y;
		centerY_w2 = car1.getWheel2().getCenter().y;
		radius_w1  = car1.getWheel1().getR();
		radius_w2  = car1.getWheel2().getR();
					
		Vec4 *p = new Vec4(centerX_w1  , centerY_w1 +  radius_w1);
		Vec4 *p2 = new Vec4(centerX_w2 , centerY_w2 +  radius_w2);
				
		Vec4 *center_w1 = new Vec4(centerX_w1, centerY_w1);
		Vec4 *center_w2 = new Vec4(centerX_w2, centerY_w2);
		
		if(!after_rotate) {
			for(int i = 0; i < 180;i += 10) {
				delay(0.001);
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, -i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, -i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y, BLUE);
			}
			
			for(int i = 180; i < 300;i += 10) {	
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, -i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, -i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y,BLUE);
			}
			
			for(int i = 300; i < 360;i += 10) {
				delay(0.001);
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, -i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, -i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y, BLUE);
			}
			
			for(int i = 0; i < 360;i += 10) {
				Vec4 *result1 = new Vec4(p->quayQuanhDiem2(center_w1, -i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem2(center_w2, -i));
				put_pixel2(result1->x, result1->y);
				put_pixel2(result2->x, result2->y);
			}		
		} else {	
			for(int i = 0; i < 180;i += 10) {
			delay(0.001);
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y, BLUE);
			}
			
			for(int i = 180; i < 300;i += 10) {	
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y,BLUE);
			}
			
			for(int i = 300; i < 360;i += 10) {
				delay(0.001);
				Vec4 *result1 = new Vec4(p->quayQuanhDiem(center_w1, i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem(center_w2, i));
				put_pixel3(result1->x, result1->y, BLUE);
				put_pixel3(result2->x, result2->y, BLUE);
			}
			
			for(int i = 0; i < 360;i += 10) {
				Vec4 *result1 = new Vec4(p->quayQuanhDiem2(center_w1, i));
				Vec4 *result2 = new Vec4(p2->quayQuanhDiem2(center_w2, i));
				put_pixel2(result1->x, result1->y);
				put_pixel2(result2->x, result2->y);
			}		
		}
}

void hienThiThongTinToaDo(Car car1, Tree tree1) {
		std::cout<<"\n-----------------------------THONG TIN TOA DO CUA XE 1--------------------------------------\n";
		//BANH XE
		std::cout<<"\nBANH XE:";
		std::cout<<"\n\t+ Tam banh xe trai: ("<<round(car1.getWheel1().getCenter().x)<<", "<<round(car1.getWheel1().getCenter().y)<<")";
		std::cout<<"\n\t+ Tam banh xe phai: ("<<round(car1.getWheel2().getCenter().x)<<", "<<round(car1.getWheel2().getCenter().y)<<")";
		std::cout<<"\n\t+ Ban kinh banh xe trai: "<<round(car1.getWheel1().getR())<<", Ban kinh banh xe phai: "<<round(car1.getWheel2().getR());
		//THAN Xy
		std::cout<<"\nTHAN XE:";
		std::cout<<"\n\t+ Dinh trai than xe: ("<<round(car1.getBody().vertex1.x)<<", "<<round(car1.getBody().vertex1.y)<<")";
		std::cout<<"\n\t+ Dinh phai than xe: ("<<round(car1.getBody().vertex4.x)<<", "<<round(car1.getBody().vertex4.y)<<")";
		std::cout<<"\n\t+ Dinh trai duoi than xe: ("<<round(car1.getBody().vertex2.x)<<", "<<round(car1.getBody().vertex2.y)<<")";
		std::cout<<"\n\t+ Dinh phai duoi than xe: ("<<round(car1.getBody().vertex3.x)<<", "<<round(car1.getBody().vertex3.y)<<")";
		//DAU XE
		std::cout<<"\nDAU XE:";
		std::cout<<"\n\t+ Dinh trai dau xe: ("<<round(car1.getHead().vertex1.x)<<", "<<round(car1.getHead().vertex1.y)<<")";
		std::cout<<"\n\t+ Dinh phai dau xe: ("<<round(car1.getHead().vertex4.x)<<", "<<round(car1.getHead().vertex4.y)<<")";
		std::cout<<"\n\t+ Dinh trai duoi dau xe: ("<<round(car1.getHead().vertex2.x)<<", "<<round(car1.getHead().vertex2.y)<<")";
		std::cout<<"\n\t+ Dinh phai duoi dau xe: ("<<round(car1.getHead().vertex3.x)<<", "<<round(car1.getHead().vertex3.y)<<")";
		//NGOI SAO
		std::cout<<"\nNGOI SAO:";
		std::cout<<"\n\t+ Tam giac o giua: ("<<round(car1.getTopStar().vertex1.x)<<", "<<round(car1.getTopStar().vertex1.y)<<"), ("<<round(car1.getTopStar().vertex2.x)<<", "<<round(car1.getTopStar().vertex2.y)<<"), ("<<round(car1.getTopStar().vertex3.x)<<", "<<round(car1.getTopStar().vertex3.y)<<")";
		std::cout<<"\n\t+ Tam giac trai: ("<<round(car1.getLeftStar().vertex1.x)<<", "<<round(car1.getLeftStar().vertex1.y)<<"), ("<<round(car1.getLeftStar().vertex2.x)<<", "<<round(car1.getLeftStar().vertex2.y)<<"), ("<<round(car1.getLeftStar().vertex3.x)<<", "<<round(car1.getLeftStar().vertex3.y)<<")";
		std::cout<<"\n\t+ Tam giac trai duoi: ("<<round(car1.getLeftBotStar().vertex1.x)<<", "<<round(car1.getLeftBotStar().vertex1.y)<<"), ("<<round(car1.getLeftBotStar().vertex2.x)<<", "<<round(car1.getLeftBotStar().vertex2.y)<<"), ("<<round(car1.getLeftBotStar().vertex3.x)<<", "<<round(car1.getLeftBotStar().vertex3.y)<<")";
		std::cout<<"\n\t+ Tam giac phai: ("<<round(car1.getRightStar().vertex1.x)<<", "<<round(car1.getRightStar().vertex1.y)<<"), ("<<round(car1.getRightStar().vertex2.x)<<", "<<round(car1.getRightStar().vertex2.y)<<"), ("<<round(car1.getRightStar().vertex3.x)<<", "<<round(car1.getRightStar().vertex3.y)<<")";
		std::cout<<"\n\t+ Tam giac duoi: ("<<round(car1.getRightBotStar().vertex1.x)<<", "<<round(car1.getRightBotStar().vertex1.y)<<"), ("<<round(car1.getRightBotStar().vertex2.x)<<", "<<round(car1.getRightBotStar().vertex2.y)<<"), ("<<round(car1.getRightBotStar().vertex3.x)<<", "<<round(car1.getRightBotStar().vertex3.y)<<")";
		std::cout<<"\n---------------------------KET THUC THONG TIN TOA DO CUA XE 1-------------------------------\n";
		
		std::cout<<"\n-----------------------------THONG TIN TOA DO CUA CAY 1--------------------------------------\n";
		//THAN CAY
		std::cout<<"\nTHAN CAY:";
		std::cout<<"\n\t+ Dinh trai than cay: ("<<round(tree1.getBody().vertex1.x)<<", "<<round(tree1.getBody().vertex1.y)<<")";
		std::cout<<"\n\t+ Dinh phai than cay: ("<<round(tree1.getBody().vertex4.x)<<", "<<round(tree1.getBody().vertex4.y)<<")";
		std::cout<<"\n\t+ Dinh trai duoi than cay: ("<<round(tree1.getBody().vertex2.x)<<", "<<round(tree1.getBody().vertex2.y)<<")";
		std::cout<<"\n\t+ Dinh phai duoi than cay: ("<<round(tree1.getBody().vertex3.x)<<", "<<round(tree1.getBody().vertex3.y)<<")";
		//NGON CAY
		std::cout<<"\nNGON CAY:";
		std::cout<<"\n\t+ Tam ngon trai: ("<<tree1.getHaftCirLeft().getCenter().getX()<<", "<<tree1.getHaftCirLeft().getCenter().getY()<<")";
		std::cout<<"\n\t+ Tam ngon giua: ("<<tree1.getHalfCirTop().getCenter().getX()<<", "<<tree1.getHalfCirTop().getCenter().getY()<<")";
		std::cout<<"\n\t+ Tam ngon phai: ("<<tree1.getHalfCirRight().getCenter().getX()<<", "<<tree1.getHalfCirRight().getCenter().getY()<<")";	
		std::cout<<"\n---------------------------KET THUC THONG TIN TOA DO CUA CAY 1-------------------------------\n";
}

