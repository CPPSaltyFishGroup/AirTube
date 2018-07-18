#include"StartScene.h"
#include"Tools.h"
#include"Object.h"
StartScene::StartScene()
{
	_background = new background();
	_start = new start();
	_end = new end();
	Scene::addObject(_background);
	Scene::addObject(_start);
	Scene::addObject(_end);
}

StartScene::~StartScene()
{
	delete _background;
	delete _start;
	delete _end;
}

void StartScene::mouseEvent(int event, int x, int y, int flags, void* param)
{
	int rx = _start->getx(),ry = _start->gety();
	int ex = _end->getx(), ey = _end->gety();
	Mat temp = _start->startImg(),temp2 = _end->exitImg();
	switch(event) {
	case CV_EVENT_MOUSEMOVE:
		if (x > rx && x < rx + temp.cols && y>ry && y<ry + temp.rows) {
			_start->setactive(true);
		}
		else if (x > ex && x < ex + temp2.cols && y>ey && y<ey + temp2.rows) {
			_end->setactive(true);
		}
		else {
			_start->setactive(false);
			_end->setactive(false);
		}
		break;
	}
}