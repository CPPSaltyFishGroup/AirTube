#pragma once
#include"Object.h"
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>
#include<set>
namespace View {
	using cv::Mat;
	class Scene {
	private:
		std::set<Object*,Object::Compare>images;
		//able to be clicked
		std::set<Object*, Object::Compare>c_images;
		//toggles
		std::set<Object*, Object::Compare>t_images;
		Mat canvasToShow;
		IplImage img;
		bool doUpdate;
	public:
		Scene();
		virtual ~Scene();
		void update();
		virtual void mouseEvent(int event, int x, int y, int flags, void* param)=0;
		void addObject(Object*);
		void removeObject(Object*);
		void pause();
		void goOn();
	};
}