#include"MainGameRunner.h"
#include"TestFile.h"
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
int main() {
	using namespace cv;
	using namespace GameUnit;
	MainGameRunner*runner = MainGameRunner::getMainGameRunner();
	runner->gameName = "HangzhouAirTube";
	runner->setScene<FuckScene>();
	runner->update();
}