#include"PlaneCreator.h"
namespace Model {
	/*
	 *    0
	 *    ¡ü
	 *1 ¡û   ¡ú 3
	 *    ¡ý
	 *    2
	 */
	int PlaneCreator::minDeltaTime=5000;
	int PlaneCreator::range[4][2] = { {20,780},{20,620},{20,780},{20,620} };
	double PlaneCreator::angular[4][2] = { {150.0,210.0},{-120.0,-60.0},{-30.0,30.0},{60.0,120.0} };
	int PlaneCreator::lastSide=0;
	int PlaneCreator::certain[4] = { -50,-50,690,850 };
}