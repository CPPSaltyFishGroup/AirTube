#pragma once
#include "Object.h"
#include"Tools.h"
using namespace GameUnit;
using namespace cv;
class start :public Object {
protected:
	Mat startImgNormal,startImgActive,start_;
	int x, y;
	bool active;
public:
	start();
	~start();
	void setactive(bool active);
	int getx() { return x; };
	int gety() { return y; };
	bool getactive() { return active; };
	Mat startImg() { return start_; };
	void update();
	void print(const Mat& canvas);
};