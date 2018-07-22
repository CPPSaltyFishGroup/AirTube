#include"ScoreManager.h"
namespace Model {
	int ScoreManager::planeReward = 3;
	int ScoreManager::score = 0;
	void ScoreManager::addPlaneReward() {
		score += planeReward;
	}
	void ScoreManager::setPlaneReward(int t) {
		planeReward = t;
	}
	void ScoreManager::clearScore() {
		score = 0;
	}
	int ScoreManager::getScore() {
		return score;
	}
}