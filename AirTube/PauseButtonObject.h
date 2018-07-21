#pragma once
#include"ToggleObject.h"
namespace View {
	class PauseButtonObject :public ToggleObject {
	private:
	protected:
	public:
		PauseButtonObject(int depth, const Point&point, const char*P1name, const char*P2name);
		void onClick(bool isLeft);
	};
}