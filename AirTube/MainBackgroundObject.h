#pragma once
#include"PictureObject.h"
namespace View {
	class MainBackgroundObject :public PictureObject {
	private:
	protected:
	public:
		MainBackgroundObject(int depth, const Point&point, const char*name);
		void onClick(bool isLeft);
	};
}