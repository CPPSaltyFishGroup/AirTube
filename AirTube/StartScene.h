#pragma once
#include"Scene.h"
#include"background.h"
#include"start.h"
#include"end.h"
#include<vector>
using namespace GameUnit;
class StartScene :public Scene {
	background *_background;
	start *_start;
	end *_end;
public:
	StartScene();
	~StartScene();
	void mouseEvent(int event,int x,int y, int flags, void* param);
};