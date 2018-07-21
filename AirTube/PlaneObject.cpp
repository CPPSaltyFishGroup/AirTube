#include"PlaneObject.h"
#include"Tools.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc.hpp>
namespace View {
	PlaneObject::PlaneObject(int depth, const Point&point) :
		PictureObject(depth, point, "GreyPlane.png") {
		attribute = 2;//1+0
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
		SHOW_PICTURE(rotatedPic);
	}
	//only used by scene
	void PlaneObject::onClick(bool isLeft) {
		//to be continued
	}
	void PlaneObject::setPosition(const Point&point) {
		position = point;
	}
}