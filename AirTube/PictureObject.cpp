#include"PictureObject.h"
#include"Tools.h"
namespace View {
	using cv::imread;
	PictureObject::PictureObject(int depth, const Point&point,const char*pictureName):
		Object(depth,point),picture(imread(pictureName,-1)) {}
	void PictureObject::print(const cv::Mat&canvas) {
		SHOW_PICTURE(picture);
	}
	bool PictureObject::mouseIn(const Point&point) {
		return position.x <= point.x&&point.x <= position.x + picture.cols&&
			position.y <= point.y&&point.y <= position.y + picture.rows;
	}
	//void PictureObject::onClick() {
	//	//to be continued;
	//}
}