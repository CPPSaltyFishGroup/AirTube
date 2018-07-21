#pragma once
#include <opencv2\opencv.hpp>
namespace Tools {
	//promise origin be in [min,max].
	template<typename T>
	inline T clamp(const T& max, const T& min, const T& origin) {
		return origin < min ? min : (origin > max ? max : origin);
	}
	int cvAdd4cMat_q(cv::Mat &dst, cv::Mat &scr, double scale);
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