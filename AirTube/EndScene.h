#pragma once
#include"Scene.h"
#include"TextObject.h"
namespace View {
	class EndScene :public Scene {
	private:
		TextObject * text;
	protected:
	public:
		EndScene();
		void setScore(int);
	};
}