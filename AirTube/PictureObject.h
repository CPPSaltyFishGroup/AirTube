#pragma once
#include"Object.h"
namespace View {
	using cv::Mat;
	class PictureObject:public Object {
	private:
	protected:
	public:
		PictureObject(int depth,const Point&point,const char*pictureName);
		Mat picture;
		//void update();
		void print(const cv::Mat&canvas);
		//only used by scene
		bool mouseIn(const Point&point);
		//void onClick();
		void setPosition(const Point&point);
	};
}