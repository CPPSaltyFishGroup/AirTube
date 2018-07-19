#include "EndBackground.h"
#include "Tools.h"
EndBackground::EndBackground()
{
	endbackground = imread("Start3.jpg");
	height = 600;
	width = 800;
	depth = 100;
}
EndBackground::~EndBackground()
{}
void EndBackground::print(const Mat& canvas) {
	Mat cache = canvas(Rect(0, 0, 800, 600));
	addWeighted(cache, 0, endbackground, 1, 0, cache);
}