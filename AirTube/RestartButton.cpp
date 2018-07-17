#include "RestartButton.h"
#include "Tools.h"
#include"Object.h"
RestartButton::RestartButton()
{
	restart1 = imread("重新开始.png",-1);
	restart2 = imread("重新开始2.png",-1);
	restart = restart1;
	x = 100;
	y = 50;
	depth = 2;
	active = false;
}
RestartButton::~RestartButton()
{}
void RestartButton::setactive(bool active)
{
	this->active = active;
}
void RestartButton::update()
{
	if (active) restart = restart2;
	else restart = restart1;
}
void RestartButton::print(const Mat& canvas)
{
	Mat cache = canvas(Rect(x, y, restart.cols, restart.rows));
	Tools::cvAdd4cMat_q(cache, restart, 1.0);
}