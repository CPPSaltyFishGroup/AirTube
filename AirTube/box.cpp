#include"Box.h"
#include"Tools.h"
Box::Box() {
	box = imread("box.jpg");
	height = 0;
	velocity = 15;
	maxVelocity = 15;
	acceleration = 1;
	depth = newdepth++;
	printf("%d\n", newdepth);
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
int Box::newdepth = 0;