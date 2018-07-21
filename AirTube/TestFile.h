#pragma once
#include"Scene.h"
#include"box.h"
#include<vector>
using namespace View;
class FuckScene:public Scene{
private:
	Box * box;
	std::vector<Box*>boxes;
public:
	FuckScene();
	~FuckScene();
	void mouseEvent(int event, int x, int y, int flags, void* param);
};