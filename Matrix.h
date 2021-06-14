#ifndef __Matrix.h
#define __Matrix.h 
namespace transformation{
	class Matrix4x4{
		public:
			Matrix4x4(){
				this->matrix4x4 = new float*[4];
				for(int i = 0; i<4; ++i){
					this->matrix4x4[i] = new float[4];
				}
			}
			
			Matrix4x4(float arr[16]){
				this->matrix4x4 = new float*[4];
				for(int i = 0; i<4; ++i){
					this->matrix4x4[i] = new float[4];
				}
				for(int i = 0; i<4; ++i){
					for(int j =0; j<4; ++j){
						this->matrix4x4[i][j]=arr[i*4+j];
					}	
				}
			}
			
			Matrix4x4(float** matrix4x4){
				this->matrix4x4 = matrix4x4;
			}
			Matrix4x4 operator*(const Matrix4x4& matrix4x4_mulBy){
				float** matrix4x4Result;
				matrix4x4Result = new float*[4];
				for(int i = 0; i<4; ++i){
					matrix4x4Result[i] = new float[4];
				}
				for(int row = 0; row< 4; ++row){
					for(int col = 0; col<4; ++col){
						matrix4x4Result[row][col] = (this->matrix4x4[row][0])*(matrix4x4_mulBy.matrix4x4[0][col])+
						this->matrix4x4[row][1]*matrix4x4_mulBy.matrix4x4[1][col]+
						this->matrix4x4[row][2]*matrix4x4_mulBy.matrix4x4[2][col]+
						this->matrix4x4[row][3]*matrix4x4_mulBy.matrix4x4[3][col];
					}
				}
				Matrix4x4 m(matrix4x4Result);
				return m;
			}
		public:
			float** matrix4x4;
	};
	class Vec4{
		public:
		Vec4():x(1),y(1),z(1),w(1){}
		Vec4(float x,float y):x(x),y(y),z(1),w(1){
		}
		Vec4(float x,float y,float z):x(x),y(y),z(z),w(1){
		}
		Vec4(float x,float y,float z,float w):x(x),y(y),z(z),w(w){
		}
		Vec4 operator*(const Matrix4x4& matrix4x4_mulBy){
			float xr = this->x*matrix4x4_mulBy.matrix4x4[0][0]+this->y*matrix4x4_mulBy.matrix4x4[1][0]+this->z*matrix4x4_mulBy.matrix4x4[2][0]+this->w*matrix4x4_mulBy.matrix4x4[3][0];
			float yr = this->x*matrix4x4_mulBy.matrix4x4[0][1]+this->y*matrix4x4_mulBy.matrix4x4[1][1]+this->z*matrix4x4_mulBy.matrix4x4[2][1]+this->w*matrix4x4_mulBy.matrix4x4[3][1];
			float zr = this->x*matrix4x4_mulBy.matrix4x4[0][2]+this->y*matrix4x4_mulBy.matrix4x4[1][2]+this->z*matrix4x4_mulBy.matrix4x4[2][2]+this->w*matrix4x4_mulBy.matrix4x4[3][2];
			float wr = w;
			Vec4 result(xr,yr,zr,wr);
			return result;
		}
		Vec4 tinhTien(int x1, int y1) {
			Vec4 result(this->getX() + x1, this->getY() + y1);
			return  result;
		}
		double convert(double degree) {
			double pi = 3.14159265359;
			return (degree*(pi/180.0));
		}
		float getX() {
			return this->x;
		}
		float getY() {
			return this->y;
		}
		Vec4 rotate(double degree) {
			float radian = convert(degree);
			int x1, y1;				
			x1 = round(this->getX()*cos(radian) - this->getY()*sin(radian));
			y1 = round(this->getX()*sin(radian) + this->getY()*cos(radian)); 
			Vec4 result(x1, y1);
			return result;
		}			
		Vec4 quayQuanhDiem(Vec4 *p, double degree) {
			Vec4 result(tinhTien(-p->x,-p->y).rotate(degree).tinhTien(p->x,p->y));
			return result;
		}
		Vec4 quayQuanhDiem2(Vec4 *p, double degree) {
			Vec4 result(tinhTien(-p->x ,-p->y).rotate(degree).tinhTien(p->x ,p->y));
			return result;
		}			
			
		public:
			float x,y,z,w;
	};
	
	Matrix4x4 translate(int x, int y){
		float arr[]={
			1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			x,y,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 scale(float x, float y){
		float arr[]={
			x,0,0,0,
			0,y,0,0,
			0,0,1,0,
			0,0,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 translate(int x, int y, int z){
		float arr[]={
			1,0,0,0,
			0,1,0,0,
			0,0,1,0,
			x,y,z,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 scale(int x, int y, int z){
		float arr[]={
			x,0,0,0,
			0,y,0,0,
			0,0,z,0,
			0,0,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 rotateX(float angle){
		float arr[]={
			1,0,0,0,
			0,cos(angle),-sin(angle),0,
			0,sin(angle),cos(angle),0,
			0,0,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 rotateY(float angle){
		float arr[]={
			cos(angle),0,sin(angle),0,
			0,1,0,0,
			-sin(angle),0,cos(angle),0,
			0,0,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
	
	Matrix4x4 rotateZ(float angle){
		float arr[]={
			cos(angle),sin(angle),0,0,
			-sin(angle),cos(angle),0,0,
			0,0,1,0,
			0,0,0,1
		};
		Matrix4x4 result(arr);
		return result;
	}
}

#endif
