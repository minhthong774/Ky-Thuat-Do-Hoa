#ifndef __Car.h
#define __Car.h
#include "Shape.h"
#include "Matrix.h"
using namespace shape;
class Car{
	public:
		Car(){				
			wheel1 		= Circle(-50, -3, 5);	
			wheel2 		= Circle(-30, -3, 5);	
			smallWheel1 = Circle(-50, -3, 2);
			smallWheel2 = Circle(-30, -3, 2);
			
			body = shape::Rectangle(-60, 20, -60, 3, -20, 3, -20, 20);
			head = shape::Rectangle(-20, 18, -20, 4,  -8, 4, -10, 18);
			
			topTriStar 			= shape::Triangle(-43, 14, -37, 14, -40, 17);
		   	leftTriStar 		= shape::Triangle(-42, 14, -48, 14, -45, 11);
		   	rightTriStar 		= shape::Triangle(-38, 14, -32, 14, -35, 11);
			leftBottomTriStar 	= shape::Triangle(-48, 6 , -45, 11, -41,  9);
			rightBottomTriStar 	= shape::Triangle(-33, 6 , -35, 11, -40,  9);
		}
		
		Car(Car *car) {
//			this->wheel1 = car.wheel1;
//			this->wheel2 = car.wheel2	
//			this->smallWheel1 = car.smallWheel1;
//			this->smallWheel2 = car.smallWheel2;
//			
//			this->body = car.body;
//			this->head = car.head;
//			
//			this->topTriStar = car.topTriStar;
//		   	this->leftTriStar = car.leftTriStar;
//		   	this->rightTriStar = car.rightTriStar;
//			this->leftBottomTriStar = car.leftBottomTriStar;
//			this->rightBottomTriStar = car.rightBottomTriStar;

			this->wheel1 = car->wheel1;
			this->wheel2 = car->wheel2;
			this->smallWheel1 = car->smallWheel1;
			this->smallWheel2 = car->smallWheel2;
			
			this->body = car->body;
			this->head = car->head;
			
			this->topTriStar = car->topTriStar;
		   	this->leftTriStar = car->leftTriStar;
		   	this->rightTriStar = car->rightTriStar;
			this->leftBottomTriStar = car->leftBottomTriStar;
			this->rightBottomTriStar = car->rightBottomTriStar;
		}
		
		void Transformation(Matrix4x4 transMatrix){
			smallWheel1.transform(transMatrix);
			smallWheel2.transform(transMatrix);
			wheel1.transform(transMatrix);
			wheel2.transform(transMatrix);
			body.transform(transMatrix);
			head.transform(transMatrix);
			leftTriStar.transform(transMatrix);
			topTriStar.transform(transMatrix);
			rightTriStar.transform(transMatrix);
			leftBottomTriStar.transform(transMatrix);
			rightBottomTriStar.transform(transMatrix);
		}
		
		void updateRadiusForWheel(float scaleFactor) {
			wheel1.calculateRadius(scaleFactor);
			wheel2.calculateRadius(scaleFactor);
			smallWheel1.calculateRadius(scaleFactor);
			smallWheel2.calculateRadius(scaleFactor);
		}
		
		Circle getWheel1() {
			return this->wheel1;
		}
		
		Circle getWheel2() {
			return this->wheel2;
		}
		
		shape::Rectangle getBody() {
			return this->body;
		}
		
		shape::Rectangle getHead() {
			return this->head;
		}
		
		Triangle getLeftStar() {
			return this->leftTriStar;
		}
		
		Triangle getTopStar() {
			return this->topTriStar;
		}
		
		Triangle getRightStar() {
			return this->rightTriStar;
		}
		
		Triangle getLeftBotStar() {
			return this->leftBottomTriStar;
		}
		
		Triangle getRightBotStar() {
			return this->rightBottomTriStar;
		}
		
		void Draw(){
			wheel1.draw();
			wheel2.draw();
			smallWheel1.draw();
			smallWheel2.draw();
			body.draw();
			head.draw();
			
			leftTriStar.draw();
			topTriStar.draw();
			rightTriStar.draw();
			leftBottomTriStar.draw();
			rightBottomTriStar.draw();
		}
	private:
		shape::Rectangle body, head;
		shape::Triangle leftTriStar, rightTriStar, topTriStar, leftBottomTriStar, rightBottomTriStar;
		Circle wheel1, wheel2, smallWheel1, smallWheel2;
};
#endif
