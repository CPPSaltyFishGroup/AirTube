#pragma once
#include"ToggleObject.h"
namespace View {
	class EndButtonObject :public ToggleObject {
	private:
	protected:
	public:
		EndButtonObject(int depth, const Point&point, const char*P1name, const char*P2name);
		void onClick(bool isLeft);
	};
}