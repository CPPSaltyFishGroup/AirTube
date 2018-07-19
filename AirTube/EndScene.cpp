#include"EndScene.h"
#include"Tools.h"
#include"Object.h"
EndScene::EndScene()
{
	EBG = new EndBackground();
	RB = new RestartButton();
	FB = new FinishButton();
	PL = new Plane("��ɫ�ɻ�1.png");
	Scene::addObject(EBG);
	Scene::addObject(RB);
	Scene::addObject(FB);
	Scene::addObject(PL);
}

EndScene::~EndScene()
{
	delete EBG;
	delete RB;
	delete FB;
	delete PL;
}

void EndScene::mouseEvent(int event, int x, int y, int flags, void* param)
{
	int rx = RB->getx(),ry = RB->gety();
	int ex = FB->getx(), ey = FB->gety();
	Mat temp = RB->getrestart(),temp2 = FB->getfinish();
	switch(event) {
	case CV_EVENT_MOUSEMOVE:
		if (x > rx && x < rx + temp.cols && y>ry && y<ry + temp.rows) {
			RB->setactive(true);
		}
		else if (x > ex && x < ex + temp2.cols && y>ey && y<ey + temp2.rows) {
			FB->setactive(true);
		}
		else {
			RB->setactive(false);
			FB->setactive(false);
		}
		break;
	case CV_EVENT_LBUTTONDOWN:
		Plane * oneplane = new Plane("��ɫ�ɻ�1.png");
		oneplane->setxy(x, y);
		Scene::addObject(oneplane);
		break;
	}
}