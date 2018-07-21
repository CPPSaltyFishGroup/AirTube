#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
#define SHOW_PICTURE(picture) \
{\
	using cv::Rect;\
	int x2=MIN(picture.cols, canvas.cols - position.x);\
	int y2=MIN(picture.rows, canvas.rows - position.y);\
	Mat bg = canvas(Rect(\
		MAX(position.x, 0),\
		MAX(position.y, 0),\
		x2,\
		y2\
	));\
	Mat sprt = picture(Rect(\
		MAX(-position.x, 0),\
		MAX(-position.y, 0),\
		x2,\
		y2\
	));\
	Tools::cvAdd4cMat_q(bg, sprt, 1.0);\
}
namespace Tools {
	//promise origin be in [min,max].
	template<typename T>
	inline T clamp(const T& max, const T& min, const T& origin) {
		return origin < min ? min : (origin > max ? max : origin);
	}
	int cvAdd4cMat_q(cv::Mat &dst, cv::Mat &scr, double scale);

	template<typename T>
	inline T square(const T&t) {
		return t * t;
	}
	/*
	template<typename T>
	inline T max(const T& a, const T& b) {
		return a > b ? a : b;
	}
	template<typename T>
	inline T min(const T& a, const T& b) {
		return a < b ? a : b;
	}
	*/
}