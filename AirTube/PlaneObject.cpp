#include"PlaneObject.h"
#include"Tools.h"
#include"GameSceneActions.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
namespace View {
	PlaneObject::PlaneObject(int depth, const Point&point) :
		PictureObject(depth, point, "GreyPlane.png") {
		position.x -= picture.cols / 2;
		position.y -= picture.rows / 2;
		rotatedPic = Mat(picture.rows, picture.cols, CV_8UC4, cv::Scalar(255, 255, 255, 255));
		attribute = 2;//1+0
		setRotation(0.0);
	}
	void PlaneObject::setRotation(double rotate) {
		static Mat m;
		using namespace cv;
		if (this->rotate == rotate)
			return;
		this->rotate = rotate;
		m = getRotationMatrix2D(Point2f(picture.cols / 2, picture.rows / 2), rotate, 1.0);
		warpAffine(picture, rotatedPic, m, Size(picture.cols, picture.rows));
	}
	void PlaneObject::print(const cv::Mat&canvas) {
		using namespace cv;
		if (position.x >= canvas.cols || position.y >= canvas.rows ||
			position.x + picture.cols <= 0 || position.y + picture.rows <= 0)
			return;
		SHOW_PICTURE(rotatedPic);
	}
	//only used by scene
	void PlaneObject::onClick(bool isLeft) {
		ViewModel::GameSceneActions::planeClick(this);
	}
	void PlaneObject::setMidPosition(const Point&point) {
		position.x = point.x - picture.cols / 2;
		position.y = point.y - picture.rows / 2;
	}
	void PlaneObject::setPosition(const Point&point) {
		position = point;
	}
}