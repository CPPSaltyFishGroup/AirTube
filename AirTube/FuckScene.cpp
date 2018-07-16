#include"TestFile.h"
#include"box.h"
FuckScene::FuckScene() {
	box = new Box();
	Scene::addObject(box);
}
FuckScene::~FuckScene() {
	
}
void FuckScene::mouseEvent(int event, int x, int y, int flags, void* param) {

}