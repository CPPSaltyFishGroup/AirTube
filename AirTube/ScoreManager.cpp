#include"ScoreManager.h"
namespace Model {
	int ScoreManager::planeReward = 1;
	int ScoreManager::score = 0;
	int ScoreManager::addPlaneReward() {
		score += planeReward;
		return score;
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