#include "background.h"
#include "Tools.h"
background::background()
{	
	depth = 4;
	backimg = imread("Start2.png");
	height = 600;
	width = 800;
}
background::~background()
{}
void background::print(const Mat& canvas) {
	Mat cache = canvas(Rect(0, 0, 800, 600));
	addWeighted(cache, 0, backimg, 1, 0, cache);
}