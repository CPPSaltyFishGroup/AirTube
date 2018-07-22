#pragma once
#include"Tools.h"
#include"Line.h"
#include"Circle.h"
#include<list>
namespace Model {
	using cv::Point;
	using std::list;
	struct Plane {
		static double rotateVelocity;
		static double moveVelocity;
		static list<Plane*>planes;


		void*UIPicture;
		double rotate;
		Point position;
		int radius;
		list<Line*>lines;
		Circle circle;
	};
}