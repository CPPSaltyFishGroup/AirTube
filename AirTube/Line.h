#pragma once
#include"Tools.h"
namespace Model {
	using cv::Scalar;
	using cv::Point;
	struct Line {
		static Scalar normalColor;
		static Scalar attachingColor;
		static int thickness;
		void*UILine;
		Point from;
		Point to;
		bool isAttachingAirport;
	};
}