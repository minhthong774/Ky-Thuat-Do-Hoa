#ifndef __Shape.h
#define __Shape.h
#include "Matrix.h"
#include "Line.h"
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
	
	class Circle{
		public:
			Circle(){
			}
			Circle(Vec4 center, int r):center(center),r(r){
			}
			Circle(int x, int y, int r):center(x,y),r(r){
			}
			void midPointCircleDraw() {
				int x_centre = center.x;
				int y_centre = center.y;
				int x= 0, y = r;
				int  p;
				int dem = 0;
				
			 	p= 5/4 - r;
			 	
				while(x < y) {
						if(r < 15) {
							if(dem %12 !=6 && dem%12!=7 ) {
							put_pixel(x_centre + x, y_centre + y);	
							put_pixel(x_centre + y, y_centre + x);
							put_pixel(x_centre - x, y_centre + y);
							put_pixel(x_centre - y, y_centre + x);
											
							put_pixel(x_centre - y, y_centre - x);
							put_pixel(x_centre - x, y_centre - y);
							put_pixel(x_centre + x, y_centre - y);
							put_pixel(x_centre + y, y_centre - x);
					}
						} else  {
							if(dem %12 !=11 && dem%12!=10 && dem%12!=9) {
							put_pixel(x_centre + x, y_centre + y);	
							put_pixel(x_centre + y, y_centre + x);
							put_pixel(x_centre - x, y_centre + y);
							put_pixel(x_centre - y, y_centre + x);
											
							put_pixel(x_centre - y, y_centre - x);
							put_pixel(x_centre - x, y_centre - y);
							put_pixel(x_centre + x, y_centre - y);
							put_pixel(x_centre + y, y_centre - x);
					}
						}
					
			
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
		private:
			Vec4 center;
			int r;
	}; 
}
#endif
