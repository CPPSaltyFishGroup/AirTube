#pragma once
namespace Model {
	class ScoreManager {
	public:
		//static void addScore(int);
		static void addPlaneReward();
		static void setPlaneReward(int);
		static void clearScore();
		static int getScore();
	private:
		static int score;
		//static int timeReward;
		static int planeReward;
	};
}