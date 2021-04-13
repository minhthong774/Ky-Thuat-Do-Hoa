#ifndef __KTDH_button__
#define __KTDH_button__
#include "xuli.h"
class Button{
	public:
		Button(){};
		Button(int left, int top, int right, int bottom, char* name){
			this->left = left;
			this->top = top;
			this->right = right;
			this->bottom = bottom;
			this->name = name;
			this->highlight = false;
			this->chose = false;
		}
		
		void set_highlight(bool highlight){
			this->highlight = highlight;
		}
		
		bool get_highlight(){
			return this->highlight;
		}
		
		bool getChose(){
			return chose;
		}
		
		void setChose(bool chose){
			this->chose = chose;
		}
		
		void visible(){
			int color=YELLOW;
			if (highlight){
				color = BLUE;
			}
			setcolor(RED);
		 	setfillstyle(SOLID_FILL, color);
		 	rectangle(left,top,right,bottom);
		 	floodfill((left+right)/2,(top+bottom)/2,RED);
		 	setbkcolor(color);
		 	outtextxy(left+5, top+5, this->name);
		}
		bool is_in_range(int x, int y){
			return (x>left&&x<right)&&(y>top&&y<bottom)?true:false;
		}
	private:
		int top, left, right, bottom;
		char* name;
		bool highlight, chose;
};
class ButtonDraw: public Button{
	public:
		ButtonDraw(){};
		ButtonDraw(int left, int top, int right, int bottom, char* name){
			Button(left, top, right, bottom, name);
		}
		void setFunctionDraw(void (*func)(int,int,int,int)){
			this->func = func;
		}
		
		void draw(int x1,int y1,int x2,int y2){
			func(x1,y1,x2,y2);
		}
		
	private:
		void (*func)(int,int,int,int);
};

#endif
