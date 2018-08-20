#pragma once
#include"Object.h"
namespace View {
	using cv::String;
	using cv::Scalar;
	class TextObject:public Object {
	private:
	protected:
	public:
		String text;
		int fontFace;
		double fontScale;
		Scalar color;
		int thickness;
		int lineType;

		TextObject(int depth,
			const Point&position,
			int fontFace=CV_FONT_HERSHEY_SIMPLEX,
			double fontScale=1.0,
			const Scalar&color=Scalar(0,0,0),
			int thickness=1,
			int lineType=8);
		void print(const cv::Mat&canvas);
		bool mouseIn(const Point&point);
	};

}