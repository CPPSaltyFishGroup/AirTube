#pragma once
#include"PictureObject.h"
namespace View {
	class BackgroundObject:public PictureObject {
	private:
	protected:
	public:
		BackgroundObject(int depth, const Point&point, const char*name);
		void onClick(bool isLeft);
	};
}