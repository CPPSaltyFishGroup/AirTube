#include"LineObject.h"
#include<opencv2\imgproc.hpp>
namespace View {

	LineObject::LineObject(
		int depth,
		const Point&position,
		const Point&target,
		const Scalar&color,
		int thickness,
		int lineType) :
		Object(depth, position),
		targetPoint(target),
		color(color),
		thickness(thickness),
		lineType(lineType) {
		attribute = 0;//0+0
	}
	void LineObject::print(const cv::Mat&canvas) {
		cv::line(canvas, position, targetPoint, color, thickness, lineType);
	}
	bool LineObject::mouseIn(const Point&point) {
		return true;
	}
}