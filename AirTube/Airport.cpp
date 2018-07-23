#include"Airport.h"
namespace Model {

	Airport::Airport(const Point&position, const Point&entrance, int radius):
		airportPicture(nullptr),
		position(position),
		entranceOffset(entrance),
		entranceRadius(radius){}
	list<Airport>Airport::airports={
		{ Point(100,100),Point(185,108),15 },
		{ Point(400,400),Point(185,108),15 },
		{ Point(500,200),Point(185,108),15 } 
	};
	bool Airport::checkIn(const Point&point) {
		using Tools::square;
		return square(entranceRadius) >= square(point.x - position.x - entranceOffset.x) + square(point.y - position.y - entranceOffset.y);
	}
}