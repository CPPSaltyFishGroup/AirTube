#include"MainGameRunner.h"
#include"EndScene.h"
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>
//using namespace cv;
int main() {
	using namespace cv;
	using namespace View;
	MainGameRunner*runner = MainGameRunner::getMainGameRunner();
	runner->gameName = "HangzhouAirTube";
	runner->setScene<EndScene>();
	runner->run();
}