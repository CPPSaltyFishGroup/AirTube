#include"PictureObject.h"
#include"Tools.h"
namespace View {
	using cv::imread;
	PictureObject::PictureObject(int depth, const Point&point,const char*pictureName):
		Object(depth,point),picture(imread(pictureName)) {
		attribute = 2;//1+0
	}
	//void PictureObject::update() {
	//	//to be continued
	//}
	void PictureObject::print(const cv::Mat&canvas) {
		using namespace cv;
		Mat bg = canvas(Rect(
			max(position.x, 0),
			max(position.y, 0),
			min(position.x, canvas.cols), 
			min(position.y, canvas.rows))
		);
		Mat sprt = picture(Rect(
			max(-position.x, 0),
			max(-position.y, 0),
			min(picture.cols, canvas.cols - position.x),
			min(picture.rows, canvas.rows - position.y)
		));
		addWeighted(bg, 0.0, picture, 1.0, 0.0, bg);
	}
	bool PictureObject::mouseIn(const Point&point) {
		return position.x <= point.x&&point.x <= position.x + picture.cols&&
			position.y <= point.y&&point.y <= position.y + picture.rows;
	}
	//void PictureObject::onClick() {
	//	//to be continued;
	//}
	void PictureObject::setPosition(const Point&point) {
		position = point;
	}
}