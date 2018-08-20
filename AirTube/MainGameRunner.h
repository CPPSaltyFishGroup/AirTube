#pragma once
#include"Scene.h"
namespace View {
	class MainGameRunner {
	private:
		static MainGameRunner*runner;
		static void mouseEvent(int event, int x, int y, int flags, void* param);
		const static int fps = 55;

		Scene*currentScene, *nextScene;
		//this class must have only one instance.
		MainGameRunner();

	public:
		const char*gameName;
		//~MainGameRunner();
		//too promise it.
		static MainGameRunner* getMainGameRunner();
		Scene*getScene();

		void run();

		//set new scene
		template<typename T>
		void setScene() {
			nextScene = new T();
		}
	};
}