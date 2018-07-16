#include"MainGameRunner.h"
#include<ctime>
namespace GameUnit {

	MainGameRunner* MainGameRunner::runner = nullptr;

	MainGameRunner::MainGameRunner() {
		currentScene = nullptr;
		nextScene = nullptr;
	}
	MainGameRunner* MainGameRunner::getMainGameRunner() {
		if (runner == nullptr)
			runner = new MainGameRunner();
		return runner;
	}
	//~MainGameRunner();

	void MainGameRunner::update() {
		time_t now=clock(),target;
		time_t delta = 1000 / fps;
		for (;;) {
			//**********do something
			if (nextScene != nullptr) {
				delete currentScene;
				currentScene = nextScene;
				nextScene = nullptr;
			}
			if (currentScene != nullptr)
				currentScene->update();
			target = clock();
			if(target<=now+delta)
				cv::waitKey(now + delta - clock());
			now = target;
		}
	}

}