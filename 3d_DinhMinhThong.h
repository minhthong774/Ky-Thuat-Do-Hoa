#ifndef __3d_DinhMinhThong__
#define __3d_DinhMinhThong__
#include "Matrix.h"
#include "Line.h"
#include "Shape.h"
using namespace transformation;
using namespace shape;
Vec4 from3Dto2DCoordinates(Vec4 coord3D){
	float arr[]={
		1, 0, 0, 0,
		0, 1, 0, 0,
		0.5*cos(3.14159265*45.0/180.0), 0.5*sin(3.14159265*45.0/180.0), 1, 0,
		0, 0, 0, 1,
	};
	Matrix4x4 trans(arr);
	
	Vec4 result = coord3D * trans;
	result.x=round(result.x);
	result.y=round(result.y);
	result.z=round(result.z);
	return result;
}
void drawRectangular(Vec4 position, int length, int width, int height){
	Vec4 A(position.x, position.y, position.z);
	Vec4 B(position.x + length, position.y, position.z);
	Vec4 C(position.x + length, position.y + width, position.z);
	Vec4 D(position.x, position.y + width, position.z);
	Vec4 E(position.x, position.y, position.z + height);
	Vec4 F(position.x + length, position.y, position.z + height);
	Vec4 G(position.x +length, position.y + width, position.z + height);
	Vec4 H(position.x, position.y + width, position.z + height);
	
	Vec4 A2D = from3Dto2DCoordinates(A);
	Vec4 B2D = from3Dto2DCoordinates(B);
	Vec4 C2D = from3Dto2DCoordinates(C);
	Vec4 D2D = from3Dto2DCoordinates(D);
	Vec4 E2D = from3Dto2DCoordinates(E);
	Vec4 F2D = from3Dto2DCoordinates(F);
	Vec4 G2D = from3Dto2DCoordinates(G);
	Vec4 H2D = from3Dto2DCoordinates(H);
	
	Line::getInstance()->drawLine(A2D, B2D);
	Line::getInstance()->drawLine(B2D, C2D);
	Line::getInstance()->drawLine(C2D, D2D);
	Line::getInstance()->drawLine(D2D, A2D);
	Line::getInstance()->drawDashedLine(A2D, E2D);
	Line::getInstance()->drawLine(B2D, F2D);
	Line::getInstance()->drawLine(C2D, G2D);
	Line::getInstance()->drawLine(D2D, H2D);
	Line::getInstance()->drawDashedLine(E2D, F2D);
	Line::getInstance()->drawLine(F2D, G2D);
	Line::getInstance()->drawLine(G2D, H2D);
	Line::getInstance()->drawDashedLine(H2D, E2D);
}

void drawCylinder(Vec4 position, int height, int radius){
	Vec4 A1(position.x, position.y, position.z);
	Vec4 B1(position.x + radius, position.y, position.z);
	Vec4 C1(position.x - radius, position.y, position.z);
	
	Vec4 A2(position.x, position.y + height, position.z);
	Vec4 B2(position.x + radius, position.y + height, position.z);
	Vec4 C2(position.x - radius, position.y + height, position.z);
	
	Vec4 D(position.x, position.y, position.z + radius);
	
	Vec4 A12D = from3Dto2DCoordinates(A1);
	Vec4 B12D = from3Dto2DCoordinates(B1);
	Vec4 C12D = from3Dto2DCoordinates(C1);
	Vec4 A22D = from3Dto2DCoordinates(A2);
	Vec4 B22D = from3Dto2DCoordinates(B2);
	Vec4 C22D = from3Dto2DCoordinates(C2);
	Vec4 D2D = from3Dto2DCoordinates(D);
	int a = B12D.x - A12D.x;
	int b = D2D.y - A12D.y;
	std::cout<<b;
	Elip elip1(A12D, a, b);
	elip1.draw();
	Elip elip2(A22D, a, b);
	elip2.draw();
	Line::getInstance()->drawLine(B12D, B22D);
	Line::getInstance()->drawLine(C12D, C22D);
}


#endif
