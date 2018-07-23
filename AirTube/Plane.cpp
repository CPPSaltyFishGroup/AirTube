#include"Plane.h"
namespace Model {
	double Plane::rotateVelocity = 5;
	double Plane::moveVelocity = 1;
	int Plane::ordinaryRadius = 30;
	int Plane::delayTime = 1000;

	list<Plane*>Plane::planes{};

	Plane::Plane() {
		overFlag = 0;
	}
}