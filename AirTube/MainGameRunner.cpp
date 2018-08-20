#include"MainGameRunner.h"
#include<ctime>
namespace View {

	MainGameRunner* MainGameRunner::runner = nullptr;

	//initialize
	MainGameRunner::MainGameRunner() {
		currentScene = nullptr;
		nextScene = nullptr;
	}

	//set the mouse evnet entry with the scene's mouse event
	void MainGameRunner::mouseEvent(int event, int x, int y, int flags, void* param) {
		runner->currentScene->mouseEvent(event, x, y, flags, param);
	}

	//get the single instance
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
		//do the update in each frame.
		for (;;) {
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
			cv::waitKey(delta);
#else
			//while debugging, this will never do waitKay()
			if(target<=now+delta)
				cv::waitKey(now + delta - target);
#endif // DEBUG
			now = clock();
		}
	}

	Scene*MainGameRunner::getScene() {
		return currentScene;
	}

}