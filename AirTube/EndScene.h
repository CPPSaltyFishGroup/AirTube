#pragma once
#include"Scene.h"
#include"EndBackground.h"
#include"RestartButton.h"
#include"FinishButton.h"
#include<vector>
using namespace GameUnit;
class EndScene :public Scene {
	EndBackground *EBG;
	RestartButton *RB;
	FinishButton *FB;
public:
	EndScene();
	~EndScene();
	void mouseEvent(int event,int x,int y, int flags, void* param);
};