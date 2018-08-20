#pragma once
#include"ToggleObject.h"
namespace View {
	class StartButtonObject :public ToggleObject {
	private:
	protected:
	public:
		StartButtonObject(int depth, const Point&point, const char*P1name,const char*P2name);
		void onClick(bool isLeft);
	};
}