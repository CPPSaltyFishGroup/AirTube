#include "FinishButton.h"
#include "Tools.h"
#include"Object.h"
FinishButton::FinishButton()
{
	finish1 = imread("结束游戏.png", -1);
	finish2 = imread("结束游戏2.png", -1);
	finish = finish1;
	x = 500;
	y = 50;
	depth = 3;
	active = false;
}
FinishButton::~FinishButton()
{}
void FinishButton::setactive(bool active)
{
	this->active = active;
}
void FinishButton::update()
{
	if (active) finish = finish2;
	else finish = finish1;
}
void FinishButton::print(const Mat& canvas)
{

	Mat cache = canvas(Rect(x, y, finish.cols, finish.rows));
	Tools::cvAdd4cMat_q(cache, finish, 1.0);
	
}