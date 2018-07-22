#include"Plane.h"
namespace Model {
	double Plane::rotateVelocity = 0.5;
	double Plane::moveVelocity = 2;

	list<Plane*>Plane::planes{};
}