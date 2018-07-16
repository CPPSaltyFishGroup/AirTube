#pragma once
#include"Scene.h"
#include"box.h"
using namespace GameUnit;
class FuckScene:public Scene{
private:
	Box * box;
public:
	FuckScene();
	~FuckScene();
	void mouseEvent(int event, int x, int y, int flags, void* param);
};