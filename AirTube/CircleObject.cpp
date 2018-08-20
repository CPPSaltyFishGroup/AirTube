#include"CircleObject.h"
#include<opencv2\imgproc.hpp>
#include"Tools.h"
namespace View {
	CircleObject::CircleObject(
		int depth,
		const Point&position,
		int radius,
		const Scalar& color,
		int thickness,
		int lineType):
		Object(depth,position),radius(radius),color(color),thickness(thickness),lineType(lineType) {
		attribute = 0;//0+0
	}
	void CircleObject::print(const Mat&canvas) {
		circle(canvas, position, radius, color, thickness, lineType);
	}
	bool CircleObject::mouseIn(const Point&point) {
		return true;
	//	using Tools::square;
	//	return square(radius) >= square(position.x - point.x) + square(position.y - point.y);
	}
	void CircleObject::setPosition(const Point&point) {
		position = point;
	}
}