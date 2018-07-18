#include "start.h"
#include "Tools.h"
#include"Object.h"
start::start()
{
	startImgNormal = imread("开始游戏.png",-1);
	startImgActive = imread("开始游戏_激活.png",-1);
	x = 30;
	y = 300;
	depth = 2;
	active = false;
}
start::~start()
{}
void start::setactive(bool active)
{
	this->active = active;
}
void start::update()
{
	if (active) start_ = startImgActive;
	else start_ = startImgNormal;
}
void start::print(const Mat& canvas)
{
	Mat cache = canvas(Rect(x, y, start_.cols, start_.rows));
	Tools::cvAdd4cMat_q(cache, start_, 1.0);
}