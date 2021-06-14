#ifndef __Tree.h
#define __Tree.h
#include "Shape.h"
#include "Matrix.h"
using namespace shape;
class Tree{
	public:
		Tree(){		
			body = shape::Rectangle(50, 51, 50, 26, 55, 26, 55, 51);
			haftCirLeft = Circle(49, 55, 10);
			haftCirTop = Circle(52, 60, 10);
			haftCirRight = Circle(55, 55, 10);
			
			trai1 = Elip(47, 53, 2, 2);
			trai2 = Elip(52, 62, 2, 2);
			trai3 = Elip(57, 57, 2, 2);
		}
		
		Tree(int x1r, int y1r, int x2r, int y2r, int x3r, int y3r, int x4r, int y4r){		
			body = shape::Rectangle(x1r, y1r, x2r, y2r, x3r, y3r, x4r, y4r);
			haftCirLeft = Circle(x1r - 1, y1r + 4, 10);
			haftCirTop = Circle(x1r + 2, y1r + 9, 10);
			haftCirRight = Circle(x4r, y4r + 4, 10);
		}
		
		shape::Rectangle getBody() {
			return this->body;
		}
		
		Circle getHaftCirLeft() {
			return this->haftCirLeft;
		}
		
		Circle getHalfCirTop() {
			return this->haftCirTop;
		}
		
		Circle getHalfCirRight() {
			return this->haftCirRight;
		}
		
		void Transformation(Matrix4x4 transMatrix){
			body.transform(transMatrix);
			haftCirLeft.transform(transMatrix);
			haftCirTop.transform(transMatrix);
			haftCirRight.transform(transMatrix);
			
			trai1.transform(transMatrix);
			trai2.transform(transMatrix);
			trai3.transform(transMatrix);
		}
		
		void updateRadiusForCircle(float scaleFactor) {
			haftCirLeft.calculateRadius(scaleFactor);
			haftCirTop.calculateRadius(scaleFactor);
			haftCirRight.calculateRadius(scaleFactor);
		}
		
		void Draw(){
			body.draw();
			
			haftCirLeft.drawHaftLeft();
			haftCirTop.drawHaftTop();
			haftCirRight.drawHaftRight();
		}
		
		void Draw2(){
			body.draw();
			trai1.draw();
			trai2.draw();
			trai3.draw();
			
			haftCirLeft.drawHaftLeft();
			haftCirTop.drawHaftTop();
			haftCirRight.drawHaftRight();
		}
		
		
	private:
		Circle haftCirLeft, haftCirTop, haftCirRight;
		shape::Rectangle body;
		Elip trai1, trai2, trai3;
};
#endif
