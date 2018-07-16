#pragma once
#include"Scene.h"
namespace GameUnit {
	class MainGameRunner {
	private:
		static MainGameRunner*runner;
		const static int fps = 70;

		Scene*currentScene, *nextScene;
		MainGameRunner();

	public:
		const char*gameName;
		//~MainGameRunner();
		static MainGameRunner* getMainGameRunner();


		void update();

		template<typename T>
		void setScene() {
			nextScene = new T();
		}
	};
}