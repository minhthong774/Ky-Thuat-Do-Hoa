#ifndef __Fence.h
#define __Fence.h
#include "Shape.h"
#include "Matrix.h"
using namespace shape;
class Fence{
	public:
		Fence(){		
			fenceTop 	= Elip(10, 14, 1, 3);
			fenceBottom = shape::Triangle(8, 7, 12, 7, 10, 10);		
		}
			
		void Transformation(Matrix4x4 transMatrix){
			fenceTop.transform(transMatrix);
			fenceBottom.transform(transMatrix);
		}
		
		void Draw(){
			fenceTop.draw();
			fenceBottom.draw();
		}
	private:
		Elip fenceTop;
		shape::Triangle fenceBottom;
};
#endif
