#include"Box.h"
#include"Tools.h"
namespace { int cnt = 0; }
#include<cstdio>
Box::Box():Object(cnt++,Point(0,0)) {
	box = imread("box.jpg");
	depth = cnt++;
	height = 0;
	velocity = 15;
	maxVelocity = 15;
	acceleration = 1;
	printf("%d\n", depth);
}

Box::~Box() {

}
void Box::update() {
	height += velocity;
	velocity -= acceleration;
	if (height < 0) {
		height = 0;
		velocity = maxVelocity;
	}
}
void Box::print(const Mat&canvas) {
	Mat cache = canvas(Rect(
		Tools::clamp(canvas.cols-box.cols,0,x),
		Tools::clamp(canvas.rows - box.rows, 0, canvas.rows - height - box.rows),
		box.cols,
		box.rows));
	addWeighted(cache, 0.5, box, 0.5, 0.0, cache);
}
bool Box::mouseIn(const Point&point) { return false; }