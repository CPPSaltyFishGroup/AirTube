#pragma once
#include"Tools.h"
#include"Line.h"
#include"Circle.h"
//#include<opencv2/core/types.hpp>
#include<list>
namespace Model {
	using cv::Point2d;
	using std::list;
	struct Plane {
		static double rotateVelocity;
		static double moveVelocity;
		static list<Plane*>planes;
		static int ordinaryRadius;
		static int delayTime;

		Plane();

		void*UIPicture;
		int overFlag;
		Point2d rotation;
		Point2d position;
		int radius;
		list<Line*>lines;
		Circle circle;
	};
}