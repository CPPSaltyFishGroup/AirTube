#include"EndSceneActions.h"
#include"ScoreManager.h"
namespace ViewModel {
	void EndSceneActions::startEndScene(View::EndScene*endScene) {
		endScene->setScore(Model::ScoreManager::getScore());
	}
}