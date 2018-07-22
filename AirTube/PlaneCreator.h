#pragma once
#include"Tools.h"
namespace Model {
	struct PlaneCreator {
		static int minDeltaTime;
		static int range[4][2];
		static double angular[4][2];
		static int certain[4];
		static int lastSide;
	};
}