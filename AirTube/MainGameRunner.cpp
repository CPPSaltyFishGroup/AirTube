#include"MainGameRunner.h"
#include<ctime>
#define DEBUG
namespace View {

	MainGameRunner* MainGameRunner::runner = nullptr;

	MainGameRunner::MainGameRunner() {
		currentScene = nullptr;
		nextScene = nullptr;
	}

	void MainGameRunner::mouseEvent(int event, int x, int y, int flags, void* param) {
		runner->currentScene->mouseEvent(event, x, y, flags, param);
	}

	MainGameRunner* MainGameRunner::getMainGameRunner() {
		if (runner == nullptr)
			runner = new MainGameRunner();
		return runner;
	}
	//~MainGameRunner();

	void MainGameRunner::run() {
		//cvSetMouseCallback(gameName, mouseEvent, nullptr);
		time_t now=clock(),target;
		time_t delta = 1000 / fps;
		for (;;) {
			//**********do something
			if (nextScene != nullptr) {
				delete currentScene;
				currentScene = nextScene;
				nextScene = nullptr;
				currentScene->update();
				cvSetMouseCallback(gameName, mouseEvent, nullptr);
			}
			else 
				currentScene->update();
			target = clock();
#ifdef DEBUG
			cv::waitKey(delta);//********************for debug
#else
			if(target<=now+delta)
				cv::waitKey(now + delta - target);
#endif // DEBUG
			now = clock();
		}
	}

}