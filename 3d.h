#define ROUND(a) (int)(a+0.5)
void VeLuoiPixel(){
	for(int i=300; i<=1000; i=i+5){
		setcolor(BLUE);
		line(i,0,i,700);
	}
	for(int i=0; i<700; i=i+5){
		line(300,i,1000,i);
	}
}

void VeTTD3D(){
	setcolor(RED);
	line(650,350,650,0);
	line(650-10,20,650,0);
	line(650+10,20,650,0);
	
	line(650,350,1000,350);
	line(1000-20,350-10,1000,350);
	line(1000-20,350+10,1000,350);
	
	line(650,350,300,700);
	line(310,690,330,680);
	line(310,690,320,670);
}
struct Point2D{
	int x;
	int y;
};
void putPixel5(int x, int y){
	x = x-x%5;
	y = y-y%5;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			setcolor(10);
			putpixel(x+i,y+j,10);
		}
	}
}
void lineMidPoint(int x1, int y1, int x2, int y2, int color, bool isSpace){
	int Dx = (x2-x1) ;
	int Dy = (y2-y1) ;
	float p = (2*Dy-Dx);
	int x = x1;
	int y = y1;
	int count = 1;
	putPixel5(x,y);
	
	if(x==x2){
		if(y2>=y1){
			while(y<y2){
				y=y+5;
				count++;
				if(count==3&&isSpace) count=0;
				else putPixel5(x,y);
				delay(10);
			}
		}
		else{
			while(y>y1){
				y=y-5;
				count++;
				if(count==3&&isSpace) count=0;
				else putPixel5(x,y);
				delay(10);
			}
		}
	}

	
	if(x<x2){
		while(x<=x2 && x2-x>5){
			if( p<=0 ){
				p += 2*Dy;
				if(y2<y1) y=y-5;
			}
			else{
				p += 2*(Dy-Dx);
				if(y2>y1) y=y+5;
			}
			++count;
			x=x+5;
			if(count==3 && isSpace ) count=0;
			else putPixel5(x,y);
			delay(10);
		}	
	}
	
}
void VeHinhHop(int dai, int rong, int cao){
	Point2D O;
	O.x=650;
	O.y=350;

	
	Point2D A ;
	A.x=O.x+dai;
	A.y=O.y;
	
	Point2D B ;
	B.x= (O.x+dai) - (rong)*(sqrt(2)/2);
	B.y=  O.y + (rong)*(sqrt(2)/2);
	
	Point2D C ;
	C.x = O.x - rong*sqrt(2)/2 ;
	C.y = O.y + rong*sqrt(2)/2 ;
	
	Point2D D;
	D.x = O.x + dai;
	D.y = O.y - cao;
	
	Point2D E;
	E.x = O.x ;
	E.y = O.y-cao;
	
	Point2D F;
	F.x = O.x - rong* (sqrt(2)/2);
	F.y = O.y - cao + rong* (sqrt(2)/2);
	
	Point2D G;
	G.x = O.x + dai - rong*(sqrt(2)/2);
	G.y = O.y - cao + rong*(sqrt(2)/2);
	
	setcolor(GREEN);
	lineMidPoint(O.x,O.y,A.x,A.y,10,1);
	lineMidPoint(B.x,B.y,A.x,A.y,10,0);
	lineMidPoint(C.x,C.y,B.x,B.y,10,0);
	lineMidPoint(C.x,C.y,O.x,O.y,10,1);
	lineMidPoint(D.x,D.y,A.x,A.y,10,0);
	lineMidPoint(E.x,E.y,O.x,O.y,10,1);
	lineMidPoint(E.x,E.y,D.x,D.y,10,0);
	lineMidPoint(F.x,F.y,C.x,C.y,10,0);
	lineMidPoint(F.x,F.y,E.x,E.y,10,0);
	lineMidPoint(G.x,G.y,B.x,B.y,10,0);
	lineMidPoint(G.x,G.y,D.x,D.y,10,0);
	lineMidPoint(F.x,F.y,G.x,G.y,10,0);
}
void putPixel(int x, int y){
	x=x-x%5;
	y=y-y%5;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			putpixel(x+i,y+j,10);
		}
	}
}
void elipMidpoint(int xc,int yc, int a, int b){
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    putPixel(xc+x, yc+y);
    putPixel(xc-x, yc+y);
    putPixel(xc+x, yc-y);
    putPixel(xc-x, yc-y);
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        putPixel(xc+x, yc+y);
	    putPixel(xc-x, yc+y);
	    putPixel(xc+x, yc-y);
	    putPixel(xc-x, yc-y);
	    delay(10);
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        y--;
        fy -= 2*a2; 
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        putPixel(xc+x, yc+y);
	    putPixel(xc-x, yc+y);
	    putPixel(xc+x, yc-y);
	    putPixel(xc-x, yc-y);
	    delay(10);
    }
}
void elipMidpointND(int xc,int yc, int a, int b){
    int x, y, fx, fy, a2, b2, p;
    x = 0;
    y = b;
    a2 = a*a;
    b2 = b*b;
    fx = 0;
    fy = 2 * a2 * y;
    putPixel(xc+x, yc+y);
    putPixel(xc-x, yc+y);
    putPixel(xc+x, yc-y);
    putPixel(xc-x, yc-y);
    int count=1;
    p = ROUND(b2 -(a2*b) + (0.25*a2));//p=b2 - a2*b +a2/4
    while(fx<fy)
    {
        x++;
        fx += 2*b2;
        if(p<0)
        {
            p += b2*(2*x + 3);//p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);//p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        ++count;
        putPixel(xc+x, yc+y);
	    putPixel(xc-x, yc+y);
	    if(count<=20) putPixel(xc+x, yc-y);
	    if(count<=20) putPixel(xc-x, yc-y);
	    if(count==40) count=0;
	    delay(10);
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
    while(y>0)
    {
        y--;
        fy -= 2*a2; 
        if(p >=0)
        {
            p += a2*(3-2*y); //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);//p=p+ b2(2x +2) + a2(3-2y)
        }
        ++count;
        putPixel(xc+x, yc+y);
	    putPixel(xc-x, yc+y);
	    if(count<=20) putPixel(xc+x, yc-y);
	    if(count<=20) putPixel(xc-x, yc-y);
	    if(count==40) count=0;
	    delay(10);
    }
}
void VeHinhTru(int r, int cao){
	elipMidpointND(650, 350   ,r , r*( sqrt(2)/2) );
	elipMidpoint(650,350-cao,r , r*( sqrt(2)/2) );
	lineMidPoint(650-r,350-cao,650-r,350,10,false);
	lineMidPoint(650+r,350-cao,650+r,350,10,false);
}
