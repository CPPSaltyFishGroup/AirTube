#include"GameSceneActions.h"
#include<list>
#include"Plane.h"
#include"Airport.h"
#include"PlaneCreator.h"
#include"ScoreManager.h"
#include"BackgroundObject.h"
#include"CircleObject.h"
namespace ViewModel {

	time_t GameSceneActions::lastTime=0;
	int GameSceneActions::planeDepth = -20000;
	int GameSceneActions::circleDepth = -10000;
	int GameSceneActions::lineDepth = -30000;
	Point GameSceneActions::newlyPosition=Point(0,0);
	double GameSceneActions::newRotate=0.0;

	MainGameRunner*GameSceneActions::runner = MainGameRunner::getMainGameRunner();
	void GameSceneActions::planeClick(const PlaneObject*) {

	}
	void GameSceneActions::backgroundClick(const Point&point) {

	}
	void GameSceneActions::sceneUpdate(View::GameScene*scene) {
		using namespace cv;
		using namespace View;
		using namespace Model;
		typedef std::list<Plane*> list_P;

		//update the planes
		for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ++it) {
			int deltaX = Plane::moveVelocity * sin((*it)->rotate*CV_PI / 360.0);
			int deltaY = -Plane::moveVelocity * cos((*it)->rotate*CV_PI / 360.0);
			(*it)->position.x += deltaX;
			(*it)->position.y += deltaY;
			void *t = (*it)->UIPicture;
			static_cast<PlaneObject*>(t)->setPosition((*it)->position);
			static_cast<CircleObject*>(t)->setPosition((*it)->position);
		}

		//check if crush

		//set new plane
		time_t currentTime = clock();
		if (currentTime >= lastTime + PlaneCreator::minDeltaTime) {
			generatePositionAndVelocity();
			Plane*t = new Plane{};
			PlaneObject*UIPlane = new PlaneObject(planeDepth++, newlyPosition);
			t->UIPicture = UIPlane;
			UIPlane->logicPlane = t;
			//logicPlane->UIPicture = UIPlane;
			scene->addObject(UIPlane);
			UIPlane->setRotation(newRotate);
			t->position = newlyPosition;
			t->rotate = newRotate;
			t->radius = 50;//can be set in namespace Model
			CircleObject*UICircle= new CircleObject(circleDepth++, newlyPosition);
			scene->addObject(UICircle);
			UICircle->radius = 100;

			Plane::planes.push_back(t);
			t->circle.UICircle = UICircle;
			lastTime = clock();
		}
	}
	void GameSceneActions::startGameScene(View::GameScene*scene) {
		using namespace Model;
		using namespace View;

		ScoreManager::clearScore();
		scene->setScore(0);
		int airportDepth = 300;
		for (list<Airport>::iterator it = Airport::airports.begin(); it != Airport::airports.end(); ++it) {
			PictureObject*pic = new BackgroundObject(airportDepth++, it->position, "airport.png");
			scene->addObject(pic);
			it->airportPicture = pic;
		}

		lastTime = clock();
	}

	void GameSceneActions::generatePositionAndVelocity() {
		using Model::PlaneCreator;
		int side = rand() & 3;
		if (side == PlaneCreator::lastSide)
			side = (~side) & 3;
		PlaneCreator::lastSide = side;
		if (side & 1) {
			//1 or 3
			GameSceneActions::newlyPosition.y =
				rand() % (PlaneCreator::range[side][1] - PlaneCreator::range[side][0]) + PlaneCreator::range[side][0];
			GameSceneActions::newlyPosition.x = PlaneCreator::certain[side];
		}
		else {
			GameSceneActions::newlyPosition.x =
				rand() % (PlaneCreator::range[side][1] - PlaneCreator::range[side][0]) + PlaneCreator::range[side][0];
			GameSceneActions::newlyPosition.y = PlaneCreator::certain[side];
		}
		newRotate = (double)rand() / RAND_MAX * (PlaneCreator::angular[side][1] - PlaneCreator::angular[side][0]) + PlaneCreator::angular[side][0];
		return;
	}
}