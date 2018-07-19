#include "MainGameRunner.h"
#include "opencv2/opencv.hpp"
#include "EndScene.h"
using namespace cv;
using namespace GameUnit;
int main() {
	MainGameRunner *runner = MainGameRunner::getMainGameRunner();
	runner->gameName = "HangzhouAirTube";
	runner->setScene<EndScene>();
	runner->run();
}


