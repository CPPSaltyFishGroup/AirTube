#pragma once
#include"Object.h"
using namespace GameUnit;
using namespace cv;
class Box :public Object {
	Mat box;
	int height;
	int velocity,maxVelocity;
	int acceleration;
public:
	int x;
	Box();
	~Box();
	void update();
	void print(const Mat&canva);
	bool mouseIn(const Point&point);
};