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

		static time_t lastTime,timeChange;
		static bool goUpdate;

		static Point newlyPosition;
		static double newRotate;
		static void generatePositionAndVelocity();
		static void createNewPlane(View::GameScene*);
		static void noChoose();
		static void removePlane(void*plane, View::GameScene*scene);
	public:
		static void planeClick(const PlaneObject*);
		static void backgroundClick(const Point&point,bool isLeft);
		static void sceneUpdate(View::GameScene*scene);
		static void startGameScene(View::GameScene*scene);
	};
}