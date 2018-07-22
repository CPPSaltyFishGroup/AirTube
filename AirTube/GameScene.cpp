#include"GameScene.h"
#include"TextObject.h"
#include"MainGameRunner.h"
#include"PlaneObject.h"
#include"GameSceneActions.h"
#include"ctime"
namespace View {
	GameScene::GameScene() {
		TextObject*score = new TextObject(-10086, Point(0, 620), CV_FONT_HERSHEY_SIMPLEX, 1);
		this->score = score;
		addObject(score);
		srand(time(0));
		ViewModel::GameSceneActions::startGameScene(this);
	}

	//do update,then print.
	void GameScene::update() {
		if (!doUpdate)
			return;
		using namespace cv;
		cvSet(&img, Scalar(255, 255, 255), nullptr);
		//(*images.begin())->print(canvasToShow);
		for (set_O::iterator it = images.begin(); it != images.end(); ++it) {
			(*it)->print(canvasToShow);
		}
		ViewModel::GameSceneActions::sceneUpdate(this);

		imshow(MainGameRunner::getMainGameRunner()->gameName, canvasToShow);
	}

	void GameScene::addAndPrintObject(Object*object) {
		images.insert(object);
		int attr = object->getAttribute();
		object->print(canvasToShow);
		if (attr & 10)
			c_images.insert(object);
		if (attr & 1)
			t_images.insert(object);
	}
	void GameScene ::setScore(int t) {
		char cache[20];
		sprintf_s(cache, "%d", t);
		score->text = "Score:"+(String(cache));
	}
}