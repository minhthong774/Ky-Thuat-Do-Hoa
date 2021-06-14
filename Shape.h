#ifndef __Shape.h
#define __Shape.h
#include "Matrix.h"
#include "Line.h"
#include "Math.h"
#define ROUND(a) (int)(a+0.5)
using namespace transformation;
namespace shape{
	class Triangle{
		public:
			Triangle(){
			}
			Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
				Vec4 tmp1 = Vec4(x1,y1);
				vertex1 = tmp1;
				
				Vec4 tmp2 = Vec4(x2,y2);
				vertex2 = tmp2;
				
				Vec4 tmp3 = Vec4(x3,y3);
				vertex3 = tmp3;
			}
			Triangle(Vec4 vertex1, Vec4 vertex2, Vec4 vertex3){
				vertex1 = vertex1;
				vertex2 = vertex2;
				vertex3 = vertex3;
			}
			void transform(Matrix4x4 matrixtransform){
				vertex1 = vertex1 * matrixtransform;
				vertex2 = vertex2 * matrixtransform;
				vertex3 = vertex3 * matrixtransform;
			}
			void draw(){
				Line::getInstance()->drawLine(vertex1, vertex2);
				Line::getInstance()->drawLine(vertex2, vertex3);
				Line::getInstance()->drawLine(vertex1, vertex3);
			} 
			
			void draw2(){
				Line::getInstance()->drawLine2(vertex1, vertex2);
				Line::getInstance()->drawLine2(vertex2, vertex3);
				Line::getInstance()->drawLine2(vertex1, vertex3);
			} 
		public:
			Vec4 vertex1,vertex2,vertex3;
	};
	
	class Rectangle{
		public:
			Rectangle(){
			}
			Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
				Vec4 tmp1 = Vec4(x1,y1);
				vertex1 = tmp1;
				
				Vec4 tmp2 = Vec4(x2,y2);
				vertex2 = tmp2;
				
				Vec4 tmp3 = Vec4(x3,y3);
				vertex3 = tmp3;
				
				Vec4 tmp4 = Vec4(x4,y4);
				vertex4 = tmp4;
			}
			Rectangle(Vec4 vertex1, Vec4 vertex2, Vec4 vertex3, Vec4 vertex4){
				vertex1 = vertex1;
				vertex2 = vertex2;
				vertex3 = vertex3;
				vertex4 = vertex4;
			}
			
			void transform(Matrix4x4 matrixtransform){
				vertex1 = vertex1 * matrixtransform;
				vertex2 = vertex2 * matrixtransform;
				vertex3 = vertex3 * matrixtransform;
				vertex4 = vertex4 * matrixtransform;
			}
			void draw(){
				Line::getInstance()->drawLine(vertex1, vertex2);
				Line::getInstance()->drawLine(vertex2, vertex3);
				Line::getInstance()->drawLine(vertex3, vertex4);
				Line::getInstance()->drawLine(vertex4, vertex1);
			}
		public:
			Vec4 vertex1,vertex2,vertex3,vertex4;
	};
	
		class Elip{
		public:
			Elip(){
			}
			Elip(Vec4 center, int a, int b):center(center),a(a),b(b){
				
			}
			Elip(int x, int y, int a, int b):center(Vec4(x,y)),a(a),b(b){
				
			}
			
			Vec4 getCenter() {
				return this->center;
			}
			
			int getR() {
				return this->a;
			}
			
			void transform(Matrix4x4 matrixtransform){
				center = center*matrixtransform;
			}
			
			void calculateRadius(float scaleFactor) {
				if(a == b) {
					if(scaleFactor < 1) {
						this->a = this->a - scaleFactor;
						this->b = this->a;
					} else {
						this->a = this->a*scaleFactor;
						this->b = this->a;
					}
				}
			}
			
			void elipMidpoint2(int color){
				int xc = center.x;
				int yc = center.y;
			    int x, y, fx, fy, a2, b2, p;
			    x = 0;
			    y = b;
			    a2 = a*a;
			    b2 = b*b;
			    fx = 0;
			    fy = 2 * a2 * y;
			    put_pixel4(xc+x, yc+y, color);
			    put_pixel4(xc-x, yc+y, color);
			    put_pixel4(xc+x, yc-y, color);
			    put_pixel4(xc-x, yc-y, color);
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
			        put_pixel4(xc+x, yc+y, color);
			    	put_pixel4(xc-x, yc+y, color);
			    	put_pixel4(xc+x, yc-y, color);
			   		put_pixel4(xc-x, yc-y, color);
			    }
			    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);
			    //
			    while(y>=0)
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
			        put_pixel4(xc+x, yc+y, color);
			    	put_pixel4(xc-x, yc+y, color);
			    	put_pixel4(xc+x, yc-y, color);
			    	put_pixel4(xc-x, yc-y, color);
			    }
			}
			
			
			void elipMidpoint(){
				if(a<b){
					int xc = center.x;
					int yc = center.y;
				    int x, y, dx, dy, d1, d2;
				    x = 0;
				    y = b;
				    d1 = (b * b) - (a * a * b) +
	                     (0.25 * a * a);
				    dx = 2 * b * b * x;
				    dy = 2 * a * a * y;
				    while(dx<dy)
				    {
				        put_pixel(xc+x, yc+y);
					    put_pixel(xc-x, yc+y);
					    put_pixel(xc+x, yc-y);
					    put_pixel(xc-x, yc-y);
				        if(d1<0)
				        {
				        	x++;
				            dx = dx + (2 * b * b);
	            			d1 = d1 + dx + (a * a);
				        }
				        else
				        {
				            x++;
				            y--;
				            dx = dx + (2 * b * b);
				            dy = dy - (2 * a * a);
				            d1 = d1 + dx - dy + (b * b);
				        }
				    }
				    d2 = ((b * b) * ((x + 0.5) * (x + 0.5)))+
			         ((a * a) * ((y - 1) * (y - 1))) -
			          (a * a * b * b);
				    while(y>=0)
				    {
				    	put_pixel(xc+x, yc+y);
					    put_pixel(xc-x, yc+y);
					    put_pixel(xc+x, yc-y);
					    put_pixel(xc-x, yc-y);
				        if(d2 >0)
				        {
				            y--;
				            dy = dy - (2 *a * a);
				            d2 = d2 + (a * a) - dy;
				        }
				        else
				        {
				            y--;
				            x++;
				            dx = dx + (2 * b * b);
				            dy = dy - (2 * a * a);
				            d2 = d2 + dx - dy + (a * a);
				        }
				        
				    }
				}
				else{
					int xc = center.x;
					int yc = center.y;
				    int x, y, dx, dy, d1, d2;
				    x = a;
				    y = 0;
				    d1 = (a * a) - (b * b * a) +
	                     (0.25 * b * b);
				    dx = 2 * b * b * x;
				    dy = 2 * a * a * y;
				    while(dx>dy)
				    {
				        put_pixel(xc+x, yc+y);
					    put_pixel(xc-x, yc+y);
					    put_pixel(xc+x, yc-y);
					    put_pixel(xc-x, yc-y);
				        if(d1<0)
				        {
				        	y++;
				            dy = dy + (2 * a * a);
	            			d1 = d1 + dy + (a * a);
				        }
				        else
				        {
				            y++;
				            x--;
				            dx = dx - (2 * b * b);
				            dy = dy + (2 * a * a);
				            d1 = d1 + dy - dx + (a * a);
				        }
				    }
				    d2 = ((b * b) * ((x - 1) * (x - 1)))+
			         ((a * a) * ((y + 0.5) * (y + 0.5))) -
			          (a * a * b * b);
				    while(x>=0)
				    {
				    	put_pixel(xc+x, yc+y);
					    put_pixel(xc-x, yc+y);
					    put_pixel(xc+x, yc-y);
					    put_pixel(xc-x, yc-y);
				        if(d2 >0)
				        {
				            x--;
				            dx = dx - (2 *b * b);
				            d2 = d2 + (y * y) - dx;
				        }
				        else
				        {
				            x--;
				            y++;
				            dx = dx - (2 * b * b);
				            dy = dy + (2 * a * a);
				            d2 = d2 + dy - dx + (b * b);
				        }
				        
				    }
				}
			}
			
			
			void midPointCircleDraw() {
				int r = a;
				int x_centre = center.x;
				int y_centre = center.y;
				int x= 0, y = r;
				int  p;
				int dem = 0;
				
			 	p= 5/4 - r;
			 	
				while(x < y) {
					put_pixel(x_centre + x, y_centre + y);	
					put_pixel(x_centre + y, y_centre + x);
					put_pixel(x_centre - x, y_centre + y);
					put_pixel(x_centre - y, y_centre + x);
									
					put_pixel(x_centre - y, y_centre - x);
					put_pixel(x_centre - x, y_centre - y);
					put_pixel(x_centre + x, y_centre - y);
					put_pixel(x_centre + y, y_centre - x);
					
			
					if( p < 0) {
						p+= 2*x +3;
					} else {
						p+= 2*x -2*y +5;	
						y--;
					}
					dem++;
					x++;	
			}
		}
		
		void haftRightCircleDraw() {
			int r = a;
				int x_centre = center.x;
				int y_centre = center.y;
				int x= 0, y = r;
				int  p;
				int dem = 0;
				
			 	p= 5/4 - r;
			 	
				while(x < y) {	
					put_pixel(x_centre + y, y_centre + x);
					put_pixel(x_centre + x, y_centre - y);
					put_pixel(x_centre + y, y_centre - x);
			
					if( p < 0) {
						p+= 2*x +3;
					} else {
						p+= 2*x -2*y +5;	
						y--;
					}
					dem++;
					x++;	
			}
		}
		
		void haftTopCircleDraw() {
			int r = a;
				int x_centre = center.x;
				int y_centre = center.y;
				int x= 0, y = r;
				int  p;
				int dem = 0;
				
			 	p= 5/4 - r;
			 	
				while(x < y) {
					put_pixel(x_centre + x, y_centre + y);	
					put_pixel(x_centre + y, y_centre + x);
					put_pixel(x_centre - x, y_centre + y);
					put_pixel(x_centre - y, y_centre + x);					
			
					if( p < 0) {
						p+= 2*x +3;
					} else {
						p+= 2*x -2*y +5;	
						y--;
					}
					dem++;
					x++;	
			}
		}
		
		void haftLeftCircleDraw() {
			int r = a;
				int x_centre = center.x;
				int y_centre = center.y;
				int x= 0, y = r;
				int  p;
				int dem = 0;
				
			 	p= 5/4 - r;
			 	
				while(x < y) {
//					put_pixel(x_centre - x, y_centre + y);
					put_pixel(x_centre - y, y_centre + x);
									
					put_pixel(x_centre - y, y_centre - x);
					put_pixel(x_centre - x, y_centre - y);				
			
					if( p < 0) {
						p+= 2*x +3;
					} else {
						p+= 2*x -2*y +5;	
						y--;
					}
					dem++;
					x++;	
			}
		}
		
			void draw(){
				if(a==b){
					midPointCircleDraw();
				}
				else{
					elipMidpoint();
				}
			}
		private:
			Vec4 center;
			float a, b;
	};
	
	class Circle{
		public:
			Circle(){
			}
			Circle(Vec4 center, int r):elip(center,r,r){
			}
			Circle(int x, int y, int r):elip(x,y,r,r){
			}
			
			Vec4 getCenter() {
			return	this->elip.getCenter();
			}
			
			int getR() {
				return this->elip.getR();
			}
			
			void transform(Matrix4x4 matrixtransform){
				this->elip.transform(matrixtransform);
			}
			void calculateRadius(float scaleFactor) {
				this->elip.calculateRadius(scaleFactor);
			}
			void draw(){
				this->elip.draw();
			}
			
			void draw2(int color) {
				this->elip.elipMidpoint2(color);
			}
			void drawHaftTop() {
				this->elip.haftTopCircleDraw();
			}
			void drawHaftLeft() {
				this->elip.haftLeftCircleDraw();
			}
			void drawHaftRight() {
				this->elip.haftRightCircleDraw();
			}
		private:
			Elip elip;
	};
	
	
}
#endif
