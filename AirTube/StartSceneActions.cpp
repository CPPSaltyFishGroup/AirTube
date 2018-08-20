#include"StartSceneActions.h"
#include"MainGameRunner.h"
#include"GameScene.h"
#include<cstdlib>
namespace ViewModel {
	void StartSceneActions::startOnClick() {
		View::MainGameRunner* mgr = View::MainGameRunner::getMainGameRunner();//set next scene
		mgr->setScene<View::GameScene>();
	}
	void StartSceneActions::endOnClick() {
		exit(0);
	}
}