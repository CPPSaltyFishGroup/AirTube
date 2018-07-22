#pragma once
#include"Scene.h"
#include"TextObject.h"
namespace View {
	class GameScene :public Scene {
	private:
		TextObject*score;
	protected:
	public:
		GameScene();
		void addAndPrintObject(Object*);
		void update();
		void setScore(int);
	};
}