#pragma once
#include"PictureObject.h"
namespace View {
	class PlaneObject :public PictureObject {
	private:
		static Mat white;
		double rotate;
		Mat rotatedPic;
	public:
		double alpha;
		void*logicPlane;
		//the position must be mid point position!!
		PlaneObject(int depth, const Point&point);
		void print(const Mat&canvas);
		void setRotation(double rotate);
		double getRotation();
		void setPosition(const Point&point);
		void setMidPosition(const Point&point);
		void onClick(bool isLeft);
		bool mouseIn(const Point&point);
		//const Mat&getPicToShow();
	};
}