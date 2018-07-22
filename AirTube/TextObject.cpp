#include"TextObject.h"
#include<opencv2/imgproc.hpp>
namespace View {

	TextObject::TextObject(int depth,
		const Point&position,
		int fontFace,
		double fontScale,
		const Scalar&color,
		int thickness,
		int lineType):
		Object(depth,position),
		fontFace(fontFace),
		fontScale(fontScale),
		color(color),
		thickness(thickness),
		lineType(lineType){

		//************************ask for score
		attribute = 0;//0+0
	}

	void TextObject::print(const cv::Mat&canvas) {
		cv::putText(canvas, text, position, fontFace, fontScale, color, thickness, lineType);
	}
	bool TextObject::mouseIn(const Point&point) {
		return true;
	}

}