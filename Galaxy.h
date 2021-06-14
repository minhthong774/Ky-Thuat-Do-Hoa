#ifndef __Galaxy.h
#define __Galaxy.h
void veButton(int small, int big, int start){
	setcolor(start);
	line(4, small, 4, big);
	line(4, small, 291, small);
	line(3, small - 1, 3, big - 1);
	line(3, small - 1, 290, small - 1);
	setcolor(12);
}
void xoaInfor(){
	for(int i = 0; i < 800; i++){
		setcolor(0);
		setbkcolor(0);
		outtextxy(600, 0 + i, "                                                                                                                                                                                                                                                                                                                                                           ");	
	}
}

void solarSystem5Pixel(int x, int y) {
		// Set initial positions of planets
			cleardevice();
			setbkcolor(0);
        	setcolor(0);
        	settextstyle(2, HORIZ_DIR, 5);
    int m=0,
        v=260,
        eh=300,
        mr=100,
        j=10,
        s=230,
        u=190,
        n=20;

    float pi=3.1424,a,b,c,d,e,f,g,h,z;
        //SUN
        setcolor(YELLOW);
        outtextxy(320 - 10,240 - 10,"Sun");
		circle(320 ,240 ,20);
		

        //Mercury
        setcolor(BLUE);
        outtextxy(320+60*sin(a)+10,240-35*cos(a) -10,"Mercury");
        circle(320+60*sin(a),240-35*cos(a),8);
        ellipse(320,240,0,360,60,35);

        //Venus
        setcolor(LIGHTGRAY);
        outtextxy(320+100*sin(b)+10,240-60*cos(b)-10,"Venus");
        circle(320+100*sin(b),240-60*cos(b),12);
        ellipse(320 ,240,0,360,100,60);

        //Earth
        setcolor(GREEN);
        outtextxy(320+130*sin(c)+10,240-80*cos(c)-10,"Earth");
        circle(320+130*sin(c),240-80*cos(c),10);
        ellipse(320 ,240,0,360,130,80);

        //Mars
        setcolor(LIGHTRED);
        outtextxy(320+170*sin(d)+10,240-100*cos(d) -10,"Mars");
        circle(320+170*sin(d) ,240-100*cos(d),11);
        ellipse(320 ,240,0,360,170,100);

        //Jupiter
        setcolor(BROWN);  
        outtextxy(320+200*sin(e)+10,240-130*cos(e) -10,"Jupiter");
        circle(320+200*sin(e),240-130*cos(e) ,14);
        ellipse(320 ,240 ,0,360,200,130);

        //Saturn
        setcolor(DARKGRAY);
        outtextxy(320+230*sin(f) +10,240-155*cos(f) -10,"Saturn");
        circle(320+230*sin(f) ,240-155*cos(f) ,12);
        ellipse(320 ,240 ,0,360,230,155);

        //Uranus
        setcolor(LIGHTBLUE);
        outtextxy(320+260*sin(g) +10,240-180*cos(g)  -10,"Uranus");
        circle(320+260*sin(g) ,240-180*cos(g) ,9);
        ellipse(320 ,240 ,0,360,260,180);

        //Neptune
        setcolor(LIGHTCYAN);
        outtextxy(320+280*sin(h) +10,240-200*cos(h)  -10,"Neptune");
        circle(320+280*sin(h) ,240-200*cos(h) ,9);
        ellipse(320 ,240 ,0,360,280,200);
        
        
    while(1)
    {
        a=(pi/180)*m++;
        b=(pi/180)*v++;
        c=(pi/180)*eh++;
        d=(pi/180)*mr++;
        e=(pi/180)*j++;
        f=(pi/180)*s++;
        g=(pi/180)*u++;
        h=(pi/180)*n++;
        n++;

        xoaInfor();
        
        veButton(488, 512, 12);
		outtextxy(7, 490, "          EXIT");
		int xx, yy;
		//delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, xx, yy);
	    	if(xx >= 4 && xx <= 592 && yy >= 488 && yy <= 512){
				veButton(488, 512, 9);
				setcolor(9);
				outtextxy(7, 490, "          EXIT");
				delay(150);
				veButton(488, 512, 12);
				outtextxy(7, 490, "          EXIT");
        	   	//////////  
        	   		setcolor(0);
					setbkcolor(15);
				   return;    	   	
        	   	//mainMenu();
        	   	/////////
			}
		}
		
		//Sun
		outtextxy(x_offset + x + 340,y_offset + y + 340,"Sun");
		Circle *circle1 = new Circle(x,y, 5);
        circle1->draw2(YELLOW);
        //Mercury
        Circle *circle2 = new Circle(25*sin(a) + x,15*cos(a) +y, 4);
        outtextxy(x_offset + x + 340 + 25*sin(a) * 5,y_offset + y + 340 - 15*cos(a) * 5,"Mercury");
		circle2->draw2(BLUE);
        Elip *elip2 = new Elip(x,y,25,15);
		elip2->elipMidpoint2(BLUE);
		//Venus
		outtextxy(x_offset + x + 340 + 25*sin(a) * 10,y_offset + y + 340 - 15*cos(a) * 10,"Venus");
		Circle *circle3 = new Circle(45*sin(a)+ x,25*cos(a) +y, 4);
        circle3->draw2(LIGHTGRAY);
        Elip *elip3 = new Elip(x,y,45,25);
		elip3->elipMidpoint2(LIGHTGRAY);
		//Earth
		outtextxy(x_offset + x + 340 + 25*sin(a) * 14,y_offset + y + 340 - 15*cos(a) * 14,"Earth");
		Circle *circle4 = new Circle(60*sin(a)+ x,40*cos(a) +y, 5);
        circle4->draw2(GREEN);
        Elip *elip4 = new Elip(x,y,60,40);
		elip4->elipMidpoint2(GREEN);
		//Mars
		outtextxy(x_offset + x + 340 + 25*sin(a) * 18,y_offset + y + 340 - 15*cos(a) * 18,"Mars");
		Circle *circle5 = new Circle(85*sin(a)+ x,55*cos(a) +y, 5);
        circle5->draw2(RED);
        Elip *elip5 = new Elip(x,y,85,55);
		elip5->elipMidpoint2(RED);
		////// In toa do 
		int i = (x_offset + x + 340)/5;
		int j = (y_offset + y + 340)/5;
		char cx[6];
		char cy[6];
		sprintf(cx, "%d", i);
		sprintf(cy, "%d", j);
		
		for(int i = 0; i < 100; i++){
			setcolor(15);
			setbkcolor(0);
			outtextxy(250, 550 + i, "                                                    		");	
		}
		
		outtextxy(200, 550, "Sun: ");outtextxy(250, 550, cx);outtextxy(270, 550, ", ");outtextxy(280, 550, cy);
		//Mercury
		i = (x_offset + x + 340 + 25*sin(a) * 5)/5;
		j = (y_offset + y + 340 - 15*cos(a) * 5)/5;
		sprintf(cx, "%d", i);
		sprintf(cy, "%d", j);
				
		outtextxy(250, 570, "											");
		outtextxy(200, 570, "Mercury: ");outtextxy(255, 570, cx);outtextxy(275, 570, ", ");outtextxy(285, 570, cy);
		
		//Venus
		i = (x_offset + x + 340 + 25*sin(a) * 10)/5;
		j = (y_offset + y + 340 - 15*cos(a) * 10)/5;
		sprintf(cx, "%d", i);
		sprintf(cy, "%d", j);
				
		outtextxy(250, 570, "											");
		outtextxy(200, 590, "Venus: ");outtextxy(250, 590, cx);outtextxy(270, 590, ", ");outtextxy(280, 590, cy);
		
		//Earth
		i = (x_offset + x + 340 + 25*sin(a) * 14)/5;
		j = (y_offset + y + 340 - 15*cos(a) * 14)/5;
		sprintf(cx, "%d", i);
		sprintf(cy, "%d", j);
				
		outtextxy(250, 570, "											");
		outtextxy(200, 610, "Earth: ");outtextxy(250, 610, cx);outtextxy(270, 610, ", ");outtextxy(280, 610, cy);
		
		//Mars
		i = (x_offset + x + 340 + 25*sin(a) * 18)/5;
		j = (y_offset + y + 340 - 15*cos(a) * 18)/5;
		sprintf(cx, "%d", i);
		sprintf(cy, "%d", j);
				
		outtextxy(250, 570, "											");
		outtextxy(200, 630, "Mars: ");outtextxy(250, 630, cx);outtextxy(270, 630, ", ");outtextxy(280, 630, cy);
		
		delay(500);
    }
    

        	   	
}




void solarSystem(int x, int y) {
		// Set initial positions of planets
		
    int m=0,
        v=260,
        eh=300,
        mr=100,
        j=10,
        s=230,
        u=190,
        n=20;

    float pi=3.1424,a,b,c,d,e,f,g,h,z;

//    int gd=DETECT,gm;
//    initgraph(&gd,&gm,"");
    /*animation*/
    
    while(1)
    {
    	 
        // Change the displacement
        a=(pi/180)*m++;
        b=(pi/180)*v++;
        c=(pi/180)*eh++;
        d=(pi/180)*mr++;
        e=(pi/180)*j++;
        f=(pi/180)*s++;
        g=(pi/180)*u++;
        h=(pi/180)*n++;
        n++;

        cleardevice();
        
		setbkcolor(0);
        setcolor(1);
        outtextxy(500, 50, "          DEMO");
        
		veButton(148, 172, 12);
		outtextxy(7, 150, "      PUT PIXEL");
		// 
		veButton(188, 212, 12);
		outtextxy(7, 190, "          EXIT");
		int xx, yy;
		//delay(0.0001);
	    if(ismouseclick(WM_LBUTTONDOWN)){
	        getmouseclick(WM_LBUTTONDOWN, xx, yy);
	        
	        if(xx >= 4 && xx <= 292 && yy >= 148 && yy <= 172){
				veButton(148, 172, 9);
				setcolor(9);
				outtextxy(7, 150, "        PUT PIXEL");
				delay(150);
				veButton(148, 172, 12);
				outtextxy(7, 150, "        PUT PIXEL");
				std::cout << "PUT PIXEL";
			
        	   	solarSystem5Pixel(0,0);
        	   	return;
			}
	        
	    	if(xx >= 4 && xx <= 292 && yy >= 188 && yy <= 212){
				veButton(188, 212, 9);
				setcolor(9);
				outtextxy(7, 190, "          EXIT");
				delay(150);
				veButton(188, 212, 12);
				outtextxy(7, 190, "          EXIT");
        	   	//effectSuriken(flag1);
        	   	//////////  
        	   		setcolor(0);
					setbkcolor(15);
				   return;    	   	
        	   	//mainMenu();
        	   	/////////
			}
		}
        //Draw the Circle and ellipse
		settextstyle(2, HORIZ_DIR, 5);
        //SUN
        setcolor(YELLOW);
        outtextxy(320 - 10  + x,240 - 10 + y,"Sun");      
		circle(320 + x,240 + y,20);
		

        //Mercury
        setcolor(BLUE);
        outtextxy(320+60*sin(a) + x+10,240-35*cos(a) + y -10,"Mercury");
        circle(320+60*sin(a) + x,240-35*cos(a) + y,8);
        ellipse(320 + x,240 + y,0,360,60,35);

        //Venus
        setcolor(LIGHTGRAY);
        outtextxy(320+100*sin(b) + x+10,240-60*cos(b) + y -10,"Venus");
        circle(320+100*sin(b) + x,240-60*cos(b) + y,12);
        ellipse(320 + x,240 + y,0,360,100,60);

        //Earth
        setcolor(GREEN);
        outtextxy(320+130*sin(c) + x+10,240-80*cos(c) + y -10,"Earth");
        circle(320+130*sin(c) + x,240-80*cos(c) + y,10);
        ellipse(320 + x,240 + y,0,360,130,80);

        //Mars
        setcolor(LIGHTRED);
        outtextxy(320+170*sin(d) + x+10,240-100*cos(d) + y -10,"Mars");
        circle(320+170*sin(d) + x,240-100*cos(d) + y,11);
        ellipse(320 + x,240 + y,0,360,170,100);

        //Jupiter
        setcolor(BROWN);  
        outtextxy(320+200*sin(e) + x+10,240-130*cos(e) + y -10,"Jupiter");
        circle(320+200*sin(e) + x,240-130*cos(e) + y,14);
        ellipse(320 + x,240 + y,0,360,200,130);

        //Saturn
        setcolor(DARKGRAY);
        outtextxy(320+230*sin(f) + x+10,240-155*cos(f) + y -10,"Saturn");
        circle(320+230*sin(f) + x,240-155*cos(f) + y,12);
        ellipse(320 + x,240 + y,0,360,230,155);

        //Uranus
        setcolor(LIGHTBLUE);
        outtextxy(320+260*sin(g) + x+10,240-180*cos(g) + y -10,"Uranus");
        circle(320+260*sin(g) + x,240-180*cos(g) + y,9);
        ellipse(320 + x,240 + y,0,360,260,180);

        //Neptune
        setcolor(LIGHTCYAN);
        outtextxy(320+280*sin(h) + x+10,240-200*cos(h) + y -10,"Neptune");
        circle(320+280*sin(h) + x,240-200*cos(h) + y,9);
        ellipse(320 + x,240 + y,0,360,280,200);
        
        //Star
        setcolor(WHITE);
        circle(320+280+ x-200,240-200+ y,1);
        circle(320+280+ x +50,240-200+ y,1);
        circle(320+280+ x,240-200+ y +50,1);
        circle(320+280+ x- 100,240-200+ y,1);
        circle(320+280+ x- 300,240-200+ y-100,1);
        circle(320+280+ x- 100,240-200+ y+100,1);
        circle(320+280+ x- 100,240-200+ y+50,1);
        circle(320+280+ x- 100,240-200+ y-50,1);
        
        circle(320+ x-200,240-200+ y + 300,1);
        circle(280+ x +50,240-200+ y+ 300,1);
        circle(320+280,240-200+ y +50+ 300,1);
        circle(320+280+ x,240-200+ y+ 300,1);
        circle(320+ x- 300,240-200+ y-100+ 300,1);
        circle(320+200+ x- 100,240-200+ y+100+ 300,1);
        circle(300+280+ x,240-200+ y+50+ 300,1);
        circle(120+280+ x- 100,240-200+ y-50+ 300,1);
        
        circle(320+ x-200,240-200+ y,1);
        circle(320+280+ x +50,240-200+ y,1);
        circle(320+280+ x,240+ y +50,1);
        circle(280+ x,240-200+ y,1);
        circle(320+280- 300,240-200+ y,1);
        circle(320+280+ x,240-200+100,1);
        circle(280+ x- 100,240-200+ y,1);
        circle(320+ x- 100,240-200+ y-50,1);
        
         circle(320+ x-200,240+500+ y,1);
        circle(320+280+ x +50,240+400+ y,1);
        circle(320+280+ x,240+ y +500,1);
        circle(280+ x,240+350+ y,1);
        circle(320+280- 300,240+500+ y,1);
        circle(320+280+ x,240-200+500,1);
        circle(280+ x- 100,240+500+ y,1);
        circle(320+ x- 100,240-200+ y+500,1);

        delay(80);
    }     	   	
}
#endif
