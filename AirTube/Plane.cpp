#include"Plane.h"
namespace Model {
	double Plane::rotateVelocity = 0.5;
	double Plane::moveVelocity = 1;

	list<Plane*>Plane::planes{};
}