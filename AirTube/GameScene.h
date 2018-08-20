#pragma once
#include"Scene.h"
#include"TextObject.h"
namespace View {
	class GameScene :public Scene {
	private:
		TextObject*score;
		time_t lastTime;
	protected:
	public:
		GameScene();
		~GameScene();
		void addAndPrintObject(Object*);
		void update();
		void setScore(int);
	};
}