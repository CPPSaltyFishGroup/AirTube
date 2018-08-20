#include"GameScene.h"
#include"TextObject.h"
#include"MainGameRunner.h"
#include"PlaneObject.h"
#include"GameSceneActions.h"
#include<ctime>
#include"MainBackgroundObject.h"
namespace View {
	GameScene::GameScene() {
		MainBackgroundObject*background = new MainBackgroundObject(0x7fffffff, Point(0, 0), "HiresScreenshot.png");
		addObject(background);
		TextObject*score = new TextObject(
			0x7ffffffe,
			Point(0, 630),
			CV_FONT_HERSHEY_SIMPLEX,
			1.0,
			Scalar(255,255,255)
		);
		this->score = score;
		addObject(score);
		srand(time(0));
		ViewModel::GameSceneActions::startGameScene(this);
	}
	GameScene::~GameScene() {

	}

	//do update,then print.
	void GameScene::update() {
		using namespace cv;
		cvSet(&img, Scalar(255, 255, 255), nullptr);
		//(*images.begin())->print(canvasToShow);
		if (doUpdate) {
			ViewModel::GameSceneActions::sceneUpdate(this);
			for (set_O::iterator it = images.begin(); it != images.end(); ++it) {
				(*it)->print(canvasToShow);
			}
			imshow(MainGameRunner::getMainGameRunner()->gameName, canvasToShow);
		}

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