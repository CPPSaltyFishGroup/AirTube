#pragma once
#include "Object.h"
#include"Tools.h"
using namespace GameUnit;
using namespace cv;
class RestartButton :public Object {
protected:
	Mat restart,restart1,restart2;
	int x, y;
	bool active;
public:
	RestartButton();
	~RestartButton();
	void setactive(bool active);
	int getx() { return x; };
	int gety() { return y; };
	bool getactive() { return active; };
	Mat getrestart() { return restart; };
	void update();
	void print(const Mat& canvas);
};