#pragma once
#include"Scene.h"
namespace GameUnit {
	class MainGameRunner {
	private:
		//Scene * currentScene;
		const static int fps = 70;
		static MainGameRunner*runner;
		MainGameRunner();
	public:
		static MainGameRunner* getMainGameRunner();
		//~MainGameRunner();

		void update();
		void setScene(Scene*);
	};
}