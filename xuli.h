#ifndef _ve_
#define _ve_
const int min = -50;
const int max = 50;
const int x_offset = 250;
const int y_offset = 30;

void reset_color(){
	setcolor(0);
	setbkcolor(15);
}

int to_screen_coord_x(int x){
	return x*5 + x_offset + max*5;
}
int to_screen_coord_y(int y){
	return -y*5 + y_offset + max*5;
}
int to_descartes_coord_x(int x){
	x=(x-x_offset)/5*5;
	return (x-max*5)/5;
}
int to_descartes_coord_y(int y){
	y=(y-y_offset)/5*5;
	return (y-max*5)/(-5);
}
int daunhay(int x,int y){
	int a=getcolor();
	int nhay=1;
	while(!kbhit()&&!ismouseclick(WM_LBUTTONDOWN)){
		int dem=0;
		if(nhay){
			setcolor(0);
			line(x,y,x,y+10);
			nhay=0;
		}
		else{
			setcolor(15);
			line(x,y,x,y+10);
			nhay=1;
		}
		while((!kbhit())&&(dem<40)){
			delay(1);
			dem++;
		}
	}
	setcolor(15);
	line(x,y,x,y+10);
	setcolor(a);
	return 1;
}

int ntocs(char* s,int x){//chuyen so thanh chuoi
	char* reverse=new char[100];
	int i=0;
	if(x<0){//truong hop so am
		s[i]=45;
		i++;
		x=-x;
	}
	while(x!=0){//dua x vao stack
		int a=x%10;
		a+=48;
		reverse[i]=a;
		x=x/10;
		i++;
	}
	if(i==0){//truong hop x=0
		reverse[i]=48;
		i++;
	}
	int length=i;
	int j = 0;
	for(int i = length-1;i>=0;i--)
	{
		s[j]=reverse[i];
		j++;
	}
	s[j]='\0';
	return 1;
}

int cston(std::string s,int* x){
	int a =0;
	if(s[0]==45){
		for(int i=1;i<s.length();i++){
			a=a*10+(s[i]-48);
		}
		a=-a;
	}
	else{
		for(int i=0;i<s.length();i++){
			a=a*10+(s[i]-48);
		}
	}
	(*x)=a;
	return 1;
}

int process_coord(){//nhap so tu ban phim
	while(kbhit()){
		char c=getch();
	}
	int length=2;
	int result=0;
	int i=0;
	int x=getx(),y=gety();
	char* s=new char[100];
	int xnhay=x,ynhay=y;
	daunhay(x,y);
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
	}
	s[i]='\0';
	if(s[0]==45){
		for(int i=1;i<strlen(s);i++){
			result=result*10+(s[i]-48);
		}
		result=-result;
	}
	else{
		for(int i=0;i<strlen(s);i++){
			result=result*10+(s[i]-48);
		}
	}
	delete[] s;
	s=NULL;
	return result;
}

#endif
