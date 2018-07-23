#include"Plane.h"
namespace Model {
	const double Plane::rotateVelocity = 5;
	const double Plane::moveVelocity = 1;
	const int Plane::ordinaryRadius = 30;
	const int Plane::delayTime = 1000;

	list<Plane*>Plane::planes{};

	Plane::Plane() {
		overFlag = 0;
	}
}