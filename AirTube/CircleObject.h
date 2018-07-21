#pragma once
#include"Object.h"
namespace View {
	using cv::Mat;
	using cv::Scalar;
	class CircleObject :public Object {
	private:
	protected:
	public:
		int radius;
		Scalar color;
		int thickness;
		int lineType;

		CircleObject(
			int depth,
			const Point&position,
			int radius=50,
			const Scalar&scalar=cvScalarAll(0),
			int thickness=2,
			int lineType=8);
		void print(const Mat&canvas);
		bool mouseIn(const Point&point);
	};
}