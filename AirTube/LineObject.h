#pragma once
#include"Object.h"
namespace View {
	using cv::Scalar;
	class LineObject:public Object {
	private:
	protected:
	public:
		Point targetPoint;
		Scalar color;
		int thickness;
		int lineType;

		LineObject(
			int depth,
			const Point&position,
			const Point&target,
			const Scalar&color=cvScalarAll(0),
			int thickness=2,
			int lineType=8);
		void print(const cv::Mat&canvas);
		bool mouseIn(const Point&point);
	};
}