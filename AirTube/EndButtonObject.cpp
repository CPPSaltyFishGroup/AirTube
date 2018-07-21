#include"EndButtonObject.h"
namespace View {
	EndButtonObject::EndButtonObject(int depth, const Point&point, const char*P1name, const char*P2name) :
		ToggleObject(depth, point, P1name, P2name) {
		attribute = 3;//1+0
	}
	void EndButtonObject::onClick(bool isLeft) {
		//do something
	}
}