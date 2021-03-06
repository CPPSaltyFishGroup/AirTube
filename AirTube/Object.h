#pragma once
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
namespace View {
	using cv::Point;
	class Object {
	protected:
		int attribute;//click+toggle
		int depth;
		Object(int depth,const Point&position);

	public:
		Point position;

		virtual ~Object();
		virtual void print(const cv::Mat&canvas) = 0;
		//only used by scene
		int getAttribute();
		//only used by scene
		virtual bool mouseIn(const Point&point) = 0;
		class Compare {
		public:
			typedef Object* Object_ptr;
			bool operator()(const Object_ptr&, const Object_ptr&)const;
		};
		class InverseCompare {
		public:
			typedef Object* Object_ptr;
			bool operator()(const Object_ptr&, const Object_ptr&)const;
		};
	};
}