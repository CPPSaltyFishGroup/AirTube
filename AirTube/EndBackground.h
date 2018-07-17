#pragma once
#include "Object.h"
using namespace GameUnit;
using namespace cv;
class EndBackground :public Object {
protected:
	Mat endbackground;
	int height, width;
public:
	EndBackground();
	~EndBackground();
	void update(){};
	void print(const Mat&canvas);
};