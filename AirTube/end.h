#pragma once
#include "Object.h"
#include"Tools.h"
using namespace GameUnit;
using namespace cv;
class end :public Object {
protected:
	Mat endImgNormal, endImgActive, end_;
	int x, y;
	bool active;
public:
	end();
	~end();
	void setactive(bool active);
	int getx() { return x; };
	int gety() { return y; };
	bool getActive() { return active; };
	Mat exitImg() { return end_; };
	void update();
	void print(const Mat& canvas);
};