#pragma once
#include "Object.h"
#include"Tools.h"
using namespace GameUnit;
using namespace cv;
class FinishButton :public Object {
protected:
	Mat finish, finish1, finish2;
	int x, y;
	bool active;
public:
	FinishButton();
	~FinishButton();
	void setactive(bool active);
	int getx() { return x; };
	int gety() { return y; };
	bool getactive() { return active; };
	Mat getfinish() { return finish; };
	void update();
	void print(const Mat& canvas);
};