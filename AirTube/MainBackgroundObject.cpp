#include"MainBackgroundObject.h"
#include"GameSceneActions.h"
namespace View {

	MainBackgroundObject::MainBackgroundObject(int depth, const Point&point, const char*name) :
		PictureObject(depth, point, name) {
		attribute = 2;//1+0
	}
	void MainBackgroundObject::onClick(bool isLeft) {
		ViewModel::GameSceneActions::backgroundClick(
			MainGameRunner::getMainGameRunner()->getScene()->currentMousePoint,
			isLeft
		);
	}
}