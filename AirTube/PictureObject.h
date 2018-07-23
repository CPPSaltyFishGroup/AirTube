#pragma once
#include"Object.h"
namespace View {
	using cv::Mat;
	class PictureObject:public Object {
	private:
	protected:
	public:
		Mat picture;
		PictureObject(int depth,const Point&point,const char*pictureName);
		virtual void print(const cv::Mat&canvas);
		//only used by scene
		virtual bool mouseIn(const Point&point);
		virtual void onClick(bool isLeft) = 0;//must be defined in son class
	};
}