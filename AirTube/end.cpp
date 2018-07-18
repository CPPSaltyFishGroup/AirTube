#include "end.h"
#include "Tools.h"
#include"Object.h"
end::end()
{
	endImgNormal = imread("退出游戏.png", -1);
	endImgActive = imread("退出游戏_激活.png", -1);
	x = 30;
	y = 400;
	depth = 3;
	active = false;
}
end::~end()
{}
void end::setactive(bool active)
{
	this->active = active;
}
void end::update()
{
	if (active) end_ = endImgActive;
	else end_ = endImgNormal;
}
void end::print(const Mat& canvas)
{
	Mat cache = canvas(Rect(x, y, end_.cols, end_.rows));
	Tools::cvAdd4cMat_q(cache, end_,1.0);
}