#ifndef __Human.h
#define __Human.h
#include "Shape.h"
using namespace shape;
class Human(){
	public:
		Human(){
			head = Circle(15,15,5);
			rightArm = Rectangle();
			leftArm = Rectangle();
			rightLeg = Rectangle();
			leftLegt = Rectangle();
			body = Circle();
		}
	private:
		Circle head;
		Rectangle rightArm, leftArm, rightLeg, leftLeg;
		Circle body;
}
#endif
