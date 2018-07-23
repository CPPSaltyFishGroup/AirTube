#include"Plane.h"
namespace Model {
	double Plane::rotateVelocity = 5;
	double Plane::moveVelocity = 1;
	int Plane::ordinaryRadius = 50;

	list<Plane*>Plane::planes{};
}