#pragma once
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
namespace GameUnit {
	class Object {
	private:
		int depth;
		Object();

	public:
		virtual ~Object() = 0;
		virtual void update() = 0;
		virtual void print(const cv::Mat&canvas) = 0;
		class Compare {
		public:
			bool operator()(const Object*&, const Object*&)const;
		};
	};
}