#pragma once
#include"PictureObject.h"
namespace View {
	class ToggleObject :public PictureObject {
	private:
	protected:
	public:
		Mat tgPicture;
		bool flag;
		ToggleObject(int depth, const Point&point, const char*picture, const char*tgPicture);
		void print(const cv::Mat&canvas);
		//virtual void onClick();//to be continued
	};
}