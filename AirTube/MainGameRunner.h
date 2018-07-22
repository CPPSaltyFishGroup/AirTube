#pragma once
#include"Scene.h"
namespace View {
	class MainGameRunner {
	private:
		static MainGameRunner*runner;
		static void mouseEvent(int event, int x, int y, int flags, void* param);
		const static int fps = 60;

		Scene*currentScene, *nextScene;
		MainGameRunner();

	public:
		const char*gameName;
		//~MainGameRunner();
		static MainGameRunner* getMainGameRunner();
		Scene*getScene();

		void run();

		template<typename T>
		void setScene() {
			nextScene = new T();
		}
	};
}