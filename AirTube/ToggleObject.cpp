#include"ToggleObject.h"
#include"Tools.h"
namespace View {
	using cv::imread;
	ToggleObject::ToggleObject(int depth, const Point&point, const char*picture, const char*tgPicture):
		PictureObject(depth,point,picture),tgPicture(imread(tgPicture,-1)),flag(false){
		attribute = 3;//1+1
	}
	void ToggleObject::print(const cv::Mat&canvas) {
		if (flag)
			SHOW_PICTURE(tgPicture)
		else
			SHOW_PICTURE(picture)
	}
}