#include "Plane.h"
#include "Tools.h"
#include"Object.h"
int Plane::pdepth = 11;
Plane::Plane()
{
}
Plane::Plane(const char* name)
{
	plane = imread(name,-1);
	rotplane = imread(name, -1);
	x = 0;
	y = 0;
	speed = 10;
	angle = 90;
	direction = 0;
	chose = false;
	depth = pdepth++;
	printf("%d\n", depth - 10);
}
Plane::~Plane()
{
}
void Plane::setchose(bool chose)
{
	this->chose = chose;
}
int Plane::getx() { return x; }
int Plane::gety() { return y; }
void Plane::setxy(int x, int y)
{
	this->x = x;
	this->y = y;
}
bool Plane::getchose(){	return chose;}
Mat Plane::getplane() { return plane; }
void Plane::update()
{
	if (chose) {
		circle(plane, Point(plane.cols / 2, plane.rows / 2), plane.cols / 2, Scalar(255, 255, 255, 255));
	}
	else {
		circle(plane, Point(plane.cols / 2, plane.rows / 2), plane.cols / 2, Scalar(255, 255, 255, 0));
	}
	angle += 6;
	Mat rot = getRotationMatrix2D(Point2f(plane.cols / 2, plane.rows / 2), angle, 1.0);
	warpAffine(plane, rotplane, rot, Size(plane.cols, plane.rows));
	/*if (angle < direction) {
		double tangle = (6 < direction - angle) ? 6 : direction - angle;
		angle += tangle;
		Mat rot=getRotationMatrix2D(Point2f(plane.cols / 2, plane.rows / 2), tangle, 1.0);
		warpAffine(plane, plane, rot, Size(plane.cols, plane.rows));
	}
	else if (angle < direction) {
		double tangle = (-6 > direction - angle) ? -6 : direction - angle;
		angle += tangle;
		Mat rot = getRotationMatrix2D(Point2f(plane.cols / 2, plane.rows / 2), tangle, 1.0);
		warpAffine(plane, plane, rot, Size(plane.cols, plane.rows));
	}
	else {
		double rad = direction / 180 * CV_PI;
		x += speed * cos(rad) / 60;
		y += speed * sin(rad) / 60;
	}*/
}
void Plane::print(const Mat& canvas) 
{
	Mat cache = canvas(Rect(
		Tools::clamp(800, 0, x), Tools::clamp(600, 0, y),
		plane.cols, plane.rows
	));
	Tools::cvAdd4cMat_q(cache, rotplane, 1);
}
void Plane::setangle(double angle)
{
	this->angle = angle;
}
void Plane::setdirection(double direct)
{
	direction = direct;
}