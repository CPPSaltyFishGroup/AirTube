#include"TestFile.h"
#include"box.h"
#include<vector>
FuckScene::FuckScene() {
	box = new Box();
	box->x = 10;
	Scene::addObject(box);
}
FuckScene::~FuckScene() {
	for (std::vector<Box*>::iterator it = boxes.begin(); it != boxes.end(); ++it)
		delete *it;
}
void FuckScene::mouseEvent(int event, int x, int y, int flags, void* param) {
	if (event != CV_EVENT_MBUTTONDOWN)
		return;
	Box*box = new Box();
	box->x = x/2;
	boxes.insert(boxes.begin(),box);
	addObject(box);
}