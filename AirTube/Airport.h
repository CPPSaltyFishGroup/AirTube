#pragma once
#include<list>
#include"Tools.h"
namespace Model {
	using cv::Point;
	using std::list;
	class Airport {
	private:
		Airport(const Point&position,const Point&entrance,int radius);
	public:
		static list<Airport>airports;
		void*airportPicture;
		Point position;
		Point entranceOffset;
		int entranceRadius;
		bool checkIn(const Point&point);
	};
}