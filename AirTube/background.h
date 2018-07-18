#pragma once
#include "Object.h"
using namespace GameUnit;
using namespace cv;
class background :public Object {

protected:
	Mat backimg;
	int height, width;

public:
	background();
	~background();
	void update(){};
	void print(const Mat&canvas);
};