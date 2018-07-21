#include"MainBackgroundObject.h"
namespace View {

	MainBackgroundObject::MainBackgroundObject(int depth, const Point&point, const char*name) :
		PictureObject(depth, point, name) {
		attribute = 2;//1+0
	}
	void MainBackgroundObject::onClick(bool isLeft) {
		//do something
	}
}