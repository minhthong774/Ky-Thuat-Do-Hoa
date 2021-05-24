#ifndef __Human.h
#define __Human.h
#include "Shape.h"
#include "Matrix.h"
using namespace shape;
class Human{
	public:
		Human(){
			head = Elip(29,28,5,5);
			rightArm = shape::Rectangle(22,21,25,17,20,10,14,14);
			leftArm = shape::Rectangle(37,22,33,17,43,11,47,15);
			rightLeg = shape::Rectangle(25,1,28,1,28,7,25,7);
			leftLeg = shape::Rectangle(30,1,33,1,33,7,30,7);
			body = Circle(29,16,10);
		}
		void Transformation(Matrix4x4 transMatrix){
			Matrix4x4 translateToO = translate(-29,-16);
			transMatrix = translate(-29,-16)*transMatrix*translate(29,16);
			head.transform(transMatrix);
			rightArm.transform(transMatrix);
			leftArm.transform(transMatrix);
			rightLeg.transform(transMatrix);
			leftLeg.transform(transMatrix);
			body.transform(transMatrix);
		}
		void Draw(){
			head.draw();
			rightArm.draw();
			leftArm.draw();
			rightLeg.draw();
			leftLeg.draw();
			body.draw();  
		}
	private:
		Elip head;
		shape::Rectangle rightArm, leftArm, rightLeg, leftLeg;
		Circle body;
};
#endif
