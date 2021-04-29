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
		
		std::string getName(){
			return this->name;
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
		 	outtextxy(left+5, top+5, name);
		 	reset_color();
		}
		bool is_in_range(int x, int y){
			return (x>left&&x<right)&&(y>top&&y<bottom)?true:false;
		}
	private:
		int top, left, right, bottom;
		char* name;
		bool highlight, chose;
};
class TextBox{
	public:
		TextBox(){};
		TextBox(int left, int top, int right, int bottom, char* name)
		{
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
		
		std::string getText(){
			return this->text;
		}
		
		std::string getName(){
			return this->name;
		}
		
		void visible(){
			int color=15;
			setcolor(0);
		 	setfillstyle(SOLID_FILL, color);
		 	rectangle(left,top,right,bottom);
		 	floodfill((left+right)/2,(top+bottom)/2,0);
		 	setbkcolor(color);
		 	reset_color();
		}
		
		bool is_in_range(int x, int y){
			return (x>left&&x<right)&&(y>top&&y<bottom)?true:false;
		}
		
		void action(){
			reset_color();
			while(kbhit()){
				char c=getch();
			}
			int length=2;
			int i=0;
			moveto(left+5,top+5);
			int x=getx(),y=gety();
			char* s=new char[100];
			int xnhay=x,ynhay=y;
			if(this->text != NULL){
				s = this->text;
				i = strlen(s);
				std::cout<<i;
				std::cout<<s;
				outtext(s);
				xnhay=getx();
				ynhay=gety();
			}
			daunhay(xnhay,ynhay);
			while((s[i]=getch())!=13){
				if(s[i]==8){//xoa 1 ki tu
					moveto(x,y);
					int a=getcolor();
					setcolor(getbkcolor());
					outtext(s);
					setcolor(a);
					moveto(x,y);
					if(i>0)s[i-1]='\0';//xoa 1 ki tu trong s
					s[i]='\0';
					outtext(s);//in ra xau s da xoa 1 ki tu
					xnhay=getx();
					ynhay=gety();
					if(i>0)i--;
					if(i==0)length=2;
				}
				else if(i<length){
					if((s[i]>=48)&&(s[i]<=57)){//chi nhan ki tu la so
							s[i+1]='\0';
							i++;
							moveto(x,y);
							outtext(s);
							xnhay=getx();
							ynhay=gety();
					}
					else if(s[i]==45&&(i==0)){
						length=3;
						s[i+1]='\0';
						i++;
						moveto(x,y);
						outtext(s);
						xnhay=getx();
						ynhay=gety();
					}
				}
				daunhay(xnhay,ynhay);
				if(ismouseclick(WM_LBUTTONDOWN)){
		 			int x,y;
		 			getmouseclick(WM_LBUTTONDOWN,x,y);
		 			if(!this->is_in_range(x,y))break;
				}
			}
			this->text = s;
		}
		
	private:
		int left, top ,right, bottom;
		char* text;
		char* name;
		bool highlight, chose;
};

#endif
