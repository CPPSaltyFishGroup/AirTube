#include"PauseButtonObject.h"
namespace View {
	PauseButtonObject::PauseButtonObject(int depth, const Point&point, const char*P1name, const char*P2name) :
		ToggleObject(depth, point, P1name, P2name) {
		attribute = 3;//1+0
	}
	void PauseButtonObject::onClick(bool isLeft) {
		//do something
	}
}