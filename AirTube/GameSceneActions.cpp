#include"GameSceneActions.h"
#include<list>
#include"Plane.h"
#include"Airport.h"
#include"PlaneCreator.h"
#include"ScoreManager.h"
#include"BackgroundObject.h"
#include"CircleObject.h"
#include"ChosenPlane.h"
#include"LineObject.h"
namespace ViewModel {

	time_t GameSceneActions::lastTime=0;
	int GameSceneActions::planeDepth = -30000;
	int GameSceneActions::circleDepth = -10000;
	int GameSceneActions::lineDepth = -20000;
	Point GameSceneActions::newlyPosition=Point(0,0);
	double GameSceneActions::newRotate=0.0;

	MainGameRunner*GameSceneActions::runner = MainGameRunner::getMainGameRunner();
	void GameSceneActions::planeClick(const PlaneObject*planeObject) {
		using namespace View;
		using namespace Model;
		if (ChosenPlane::chosenPlane != nullptr) {
			if (ChosenPlane::chosenPlane != planeObject->logicPlane)
				noChoose();
			else {
				return;
			}
		}
		ChosenPlane::chosenPlane = static_cast<Plane*>(planeObject->logicPlane);
		static_cast<CircleObject*>(ChosenPlane::chosenPlane->circle.UICircle)->radius = Plane::ordinaryRadius;
		return;
	}
	void GameSceneActions::backgroundClick(const Point&point,bool isLeft) {
		using Model::ChosenPlane;
		using Model::Plane;
		Plane*plane = ChosenPlane::chosenPlane;
		if (plane != nullptr) {
			if (isLeft) {
				using namespace Model;
				using namespace View;
				Line*line = new Line();
				line->to = point;
				for (list<Airport>::iterator it = Airport::airports.begin(); it != Airport::airports.end(); ++it) {
					if (it->checkIn(point)) {
						line->isAttachingAirport = true;
						break;
					}
				}
				if (plane->lines.empty()) {
					line->from = plane->position;
					//set logic plane's rotation
					plane->rotation = line->to - line->from;
				}
				else
					line->from = plane->lines.back()->to;
				LineObject*UILine = new LineObject(
					lineDepth++,
					line->from,
					line->to,
					line->isAttachingAirport ? Line::attachingColor : Line::normalColor
				);
				line->UILine = UILine;
				plane->lines.push_back(line);
				runner->getScene()->addObject(UILine);
			}
			else
				noChoose();
		}
	}
	void GameSceneActions::sceneUpdate(View::GameScene*scene) {
		using namespace cv;
		using namespace View;
		using namespace Model;
		typedef std::list<Plane*> list_P;


		//*********************************warning!!!!!!!after pause,clear the lines and planes!!!!


		//update the planes
		for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ++it) {
			using Tools::square;
			if (!(*it)->lines.empty()) {
				using Tools::square;
				//first,change position
				Line*line = (*it)->lines.front();
				if (square(Plane::moveVelocity) > square((*it)->position.x - line->to.x) + square((*it)->position.y - line->to.y)) {
					scene->removeObject(static_cast<Object*>(line->UILine));
					delete line->UILine;
					delete line;
					(*it)->lines.pop_front();
					if ((*it)->lines.empty())
						goto out;
					else
						line = (*it)->lines.front();
				}
				//change line position
				static_cast<LineObject*>(line->UILine)->position = line->from = (*it)->position;
				(*it)->rotation = line->to - line->from;
			}
		out:
			double scale = Plane::moveVelocity / sqrt(square((*it)->rotation.x) + square((*it)->rotation.y));
			double deltaX = (*it)->rotation.x*scale;
			double deltaY = (*it)->rotation.y*scale;
			(*it)->position.x += deltaX;
			(*it)->position.y += deltaY;
			static_cast<PlaneObject*>((*it)->UIPicture)->setMidPosition((*it)->position);
			static_cast<CircleObject*>((*it)->circle.UICircle)->setPosition((*it)->position);

		}

		//check if crush
		/*
		for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ++it) {
			for (list_P::iterator it2 = Plane::planes.begin(); it2 != Plane::planes.end(); ++it2) {
				if(square(Plane::ordinaryRadius)<=square((*it)->))
			}
		}*/

		//set new plane
		time_t currentTime = clock();
		if (currentTime >= lastTime + PlaneCreator::minDeltaTime)
			createNewPlane(scene);
	}

	void GameSceneActions::noChoose() {
		using Model::ChosenPlane;
		using View::CircleObject;
		(static_cast<CircleObject*>(ChosenPlane::chosenPlane->circle.UICircle))->radius = 0;
		ChosenPlane::chosenPlane = nullptr;
	}

	void GameSceneActions::createNewPlane(View::GameScene*scene) {
		using Model::Plane;
		using View::CircleObject;
		generatePositionAndVelocity();
		Plane*t = new Plane{};
		PlaneObject*UIPlane = new PlaneObject(planeDepth++, newlyPosition);
		t->UIPicture = UIPlane;
		UIPlane->logicPlane = t;
		//logicPlane->UIPicture = UIPlane;
		scene->addObject(UIPlane);
		UIPlane->setRotation(newRotate);
		t->position = newlyPosition;
		t->rotation.x = -sin(newRotate * 2 * CV_PI / 360.0);
		t->rotation.y = -cos(newRotate * 2 * CV_PI / 360.0);
		t->radius = Plane::ordinaryRadius;//can be set in namespace Model
		CircleObject*UICircle = new CircleObject(circleDepth++, newlyPosition);
		scene->addObject(UICircle);
		UICircle->radius = 0;

		Plane::planes.push_back(t);
		t->circle.UICircle = UICircle;
		lastTime = clock();
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