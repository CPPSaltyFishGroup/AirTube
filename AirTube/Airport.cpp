#include"Airport.h"
namespace Model {

	Airport::Airport(const Point&position, const Point&entrance, int radius):
		airportPicture(nullptr),
		position(position),
		entranceOffset(entrance),
		entranceRadius(radius){}
	list<Airport>Airport::airports={
		{ Point(200,200),Point(91,60),5 },
		{ Point(400,400),Point(91,60),5},
		{ Point(600,200),Point(91,60),5 } 
	};
	bool Airport::checkIn(const Point&point) {
		using Tools::square;
		return square(entranceRadius) >= square(point.x - position.x - entranceOffset.x) + square(point.y - position.y - entranceOffset.y);
	}
}