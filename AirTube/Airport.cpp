#include"Airport.h"
namespace Model {

	Airport::Airport(const char*name,const Point&position, const Point&entrance, int radius):
		name(name),
		airportPicture(nullptr),
		position(position),
		entranceOffset(entrance),
		entranceRadius(radius){}
	list<Airport>Airport::airports={
		{ "airport.png",Point(100,100),Point(185,108),15 },
		{ "airport.png",Point(300,400),Point(185,108),15 },
		{ "airport90.png",Point(500,200),Point(42,185),15 }
	};
	bool Airport::checkIn(const Point&point) {
		using Tools::square;
		return square(entranceRadius) >= square(point.x - position.x - entranceOffset.x) + square(point.y - position.y - entranceOffset.y);
	}
}