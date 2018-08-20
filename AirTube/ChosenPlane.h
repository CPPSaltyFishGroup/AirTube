#pragma once
namespace Model {
	struct Plane;
	struct ChosenPlane {
		static Plane*chosenPlane;
		static bool isFirstTime;
	};
}