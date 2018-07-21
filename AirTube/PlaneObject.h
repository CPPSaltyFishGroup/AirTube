#pragma once
#include"PictureObject.h"
namespace View {
	class PlaneObject :public PictureObject {
	private:
		double rotate;
		Mat rotatedPic;
	public:
		PlaneObject(int depth, const Point&point);
		void print(const Mat&canvas);
		void setRotation(double rotate);
		void setPosition(const Point&point);
		void onClick(bool isLeft);
		//const Mat&getPicToShow();
	};
}