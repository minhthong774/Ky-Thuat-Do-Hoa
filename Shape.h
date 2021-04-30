#ifndef __Shape.h
#define __Shape.h
#include Matrix.h
#include Line.h
using namespace transformation;
namespace shape{
	class Triangle{
		public:
			Triangle(){
			}
			Triangle(int x1, int y1, int x2, int y2, int x3, int y3){
				vertex1 = new Vec4(x1,y1);
				vertex2 = new Vec4(x1,y1);
				vertex3 = new Vec4(x1,y1);
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
				Line.getInstance().drawLine(vertex1, vertex2);
				Line.getInstance().drawLine(vertex2, vertex3);
				Line.getInstance().drawLine(vertex1, vertex3);
			} 
		public:
			Vec4* vertex1,vertex2,vertex3;
	};
	
	class Rectangle{
		public:
			Rectangle(){
			}
			Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4){
				vertex1 = new Vec4(x1,y1);
				vertex2 = new Vec4(x1,y1);
				vertex3 = new Vec4(x1,y1);
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
				Line.getInstance().drawLine(vertex1, vertex2);
				Line.getInstance().drawLine(vertex2, vertex3);
				Line.getInstance().drawLine(vertex3, vertex4);
				Line.getInstance().drawLine(vertex4, vertex1);
			}
		public:
			Vec4* vertex1,vertex2,vertex3,vertex4;
	};
	
}
#endif
