#pragma once
#include "Object.h"
#include"Tools.h"
#include<string>
using namespace GameUnit;
using namespace cv;
class Plane :public Object {
protected:
	Mat plane,rotplane;
	int x, y,speed;
	double angle,direction;
	bool chose;
	static int pdepth;
public:
	Plane();
	Plane(const char* name);
	~Plane();
	void setchose(bool chose);
	int getx() ;
	int gety() ;
	void setangle(double angle);
	void setdirection(double direct);
	void setxy(int x, int y);
	bool getchose() ;
	Mat getplane() ;
	void update();
	void print(const Mat& canvas);
};
