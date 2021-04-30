#ifndef __Shape.h
#define __Shape.h
#include "Matrix.h""
#include "baitapNho.h"
namespace shape{
	class Line{
		public:
			Line getInstance(){
				if(this->instance == NULL){
					this->instance = new Line();
				}
				return instance;
			}
			void drawLine(Vec4 vertex1, Vec4 vertex2){
				int x1 = vertex1.x;
				int y1 = vertex1.y;
				int x2 = vertex2.x;
				int y2 = vertex2.y;
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
							put_pixel(x, y);
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
								put_pixel(x, y);
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
							put_pixel(x, y);
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
								put_pixel(x, y);
							}
					}
				}
			}
		private:
			static Line instance;
	};
}
#endif
