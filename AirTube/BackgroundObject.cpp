#include"BackgroundObject.h"
namespace View {

	BackgroundObject::BackgroundObject(int depth, const Point&point, const char*name) :
		PictureObject(depth, point, name) {
		attribute = 0;//0+0
	}
	void BackgroundObject::onClick(bool isLeft) {
		//do nothing
	}
}