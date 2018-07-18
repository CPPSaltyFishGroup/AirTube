#pragma once
#include"Object.h"
using namespace GameUnit;
using namespace cv;
class Box :public Object {
	Mat box;
	static int newdepth;
	int height;
	int velocity,maxVelocity;
	int acceleration;
public:
	int x;
	Box();
	~Box();
	void update();
	void print(const Mat&canva);
};