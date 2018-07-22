#pragma once
#include"PlaneObject.h"
#include"MainGameRunner.h"
#include"GameScene.h"
namespace ViewModel {
	using View::PlaneObject;
	using cv::Point;
	using View::MainGameRunner;
	class GameSceneActions {
	private:
		static MainGameRunner*runner;

		static time_t lastTime;
		static int planeDepth;
		static int circleDepth;
		static int lineDepth;

		static Point newlyPosition;
		static double newRotate;
		static void generatePositionAndVelocity();
	public:
		static void planeClick(const PlaneObject*);
		static void backgroundClick(const Point&point);
		static void sceneUpdate(View::GameScene*scene);
		static void startGameScene(View::GameScene*scene);
	};
}