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
#include"EndScene.h"
namespace ViewModel {

	time_t GameSceneActions::lastTime=0;
	bool  GameSceneActions::goUpdate = false;
	int GameSceneActions::planeDepth = -30000;
	int GameSceneActions::circleDepth = -10000;
	int GameSceneActions::lineDepth = -20000;
	Point GameSceneActions::newlyPosition=Point(0,0);
	double GameSceneActions::newRotate=0.0;

	MainGameRunner*GameSceneActions::runner = MainGameRunner::getMainGameRunner();
	void GameSceneActions::planeClick(const PlaneObject*planeObject) {
		using namespace View;
		using namespace Model;
		if (static_cast<Plane*>(planeObject->logicPlane)->overFlag)
			return;
		if (ChosenPlane::chosenPlane != nullptr) {
			if (ChosenPlane::chosenPlane != planeObject->logicPlane)
				noChoose();
			else {
				return;
			}
		}
		ChosenPlane::isFirstTime = true;
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
				if (ChosenPlane::isFirstTime) {
					ChosenPlane::isFirstTime = false;
					for (list<Line*>::iterator it = plane->lines.begin(); it != plane->lines.end(); ++it) {
						runner->getScene()->removeObject(static_cast<Object*>((*it)->UILine));
						delete (*it)->UILine;
						delete *it;
					}
					plane->lines.clear();
				}
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

		if (!goUpdate) {
			if (clock() >= lastTime + 3000) {
				for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ++it)
					removePlane(*it, scene);
				Plane::planes.clear();
				runner->setScene<EndScene>();
			}
			return;
		}

		//update the planes
		for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ) {
			if ((*it)->overFlag) {
				if ((*it)->overFlag + Plane::delayTime <= clock()) {
					list_P::iterator next = it++;
					removePlane(*next, scene);
					Plane::planes.erase(next);
				}
				else
					++it;
				continue;
			}
			using Tools::square;
			if (!(*it)->lines.empty()) {
				using Tools::square;
				//first,change position
				Line*line = (*it)->lines.front();
				if (square(Plane::moveVelocity) > square((*it)->position.x - line->to.x) + square((*it)->position.y - line->to.y)) {
					if (line->isAttachingAirport) {
						if (ChosenPlane::chosenPlane == (*it))
							noChoose();
						static_cast<PlaneObject*>((*it)->UIPicture)->alpha = 0.95;
						scene->setScore(ScoreManager::addPlaneReward());
						(*it)->overFlag = clock();
						//set flag,and delay the deletion to happen*****************
						continue;
					}
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
			PlaneObject*UIPlane = static_cast<PlaneObject*>((*it)->UIPicture);
			UIPlane->setMidPosition((*it)->position);
			static_cast<CircleObject*>((*it)->circle.UICircle)->setPosition((*it)->position);

			//change rotation
			double arc = acos((*it)->rotation.x / sqrt(square((*it)->rotation.x) + square((*it)->rotation.y)));
			if ((*it)->rotation.y > 0)
				arc = 1.5*CV_PI - arc;
			else
				arc = arc - 0.5*CV_PI;
			double r = arc * 180 / CV_PI - UIPlane->getRotation();
			while (r > 180.0)
				r -= 360.0;
			while (r < -180.0)
				r += 360.0;
			if (r > Plane::rotateVelocity)
				UIPlane->setRotation(UIPlane->getRotation() + Plane::rotateVelocity);
			if (r < -Plane::rotateVelocity)
				UIPlane->setRotation(UIPlane->getRotation() - Plane::rotateVelocity);

			++it;//sometimes won't
		}

		//check if crush
		for (list_P::iterator it = Plane::planes.begin(); it != Plane::planes.end(); ++it) {
			if ((*it)->overFlag)
				continue;
			if ((*it)->position.y<PlaneCreator::certain[0] ||
				(*it)->position.x<PlaneCreator::certain[1] ||
				(*it)->position.y>PlaneCreator::certain[2] ||
				(*it)->position.x>PlaneCreator::certain[3]) {
				static_cast<CircleObject*>((*it)->circle.UICircle)->radius = Plane::ordinaryRadius*2;
				lastTime = clock();
				//scene->pause();
				goUpdate = false;
				return;
			}
			for (list_P::iterator it2 = Plane::planes.begin(); it2 != Plane::planes.end(); ++it2) {
				if ((*it2)->overFlag)
					continue;
				if (*it == *it2)
					continue;
				using Tools::square;
				if (square(Plane::ordinaryRadius*2) >= square((*it)->position.x - (*it2)->position.x) + square((*it)->position.y - (*it2)->position.y)) {
					static_cast<CircleObject*>((*it)->circle.UICircle)->radius = Plane::ordinaryRadius;
					static_cast<CircleObject*>((*it2)->circle.UICircle)->radius = Plane::ordinaryRadius;
					lastTime = clock();
					//scene->pause();
					goUpdate = false;
					return;
				}
			}
		}

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
		goUpdate = true;
		ChosenPlane::chosenPlane = nullptr;
		ChosenPlane::isFirstTime = false;

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

	void GameSceneActions::removePlane(void*p,View::GameScene*scene) {
		using namespace Model;
		using namespace View;
		Plane*plane = static_cast<Plane*>(p);
		scene->removeObject(static_cast<Object*>(plane->circle.UICircle));
		delete plane->circle.UICircle;
		for (list<Line*>::iterator it = plane->lines.begin(); it != plane->lines.end(); ++it) {
			scene->removeObject(static_cast<Object*>((*it)->UILine));
			delete (*it)->UILine;
		}
		scene->removeObject(static_cast<Object*>(plane->UIPicture));
		delete plane->UIPicture;
		delete plane;
	}
}