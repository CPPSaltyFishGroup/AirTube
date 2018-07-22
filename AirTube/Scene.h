#pragma once
#include"Object.h"
//#include <opencv2/core/core.hpp>  
//#include <opencv2/highgui/highgui.hpp>
#include<set>
namespace View {
	using cv::Mat;
	typedef std::set<Object*, Object::Compare> set_O;
	class Scene {
	protected:
		set_O images;
		//able to be clicked
		set_O c_images;
		//toggles
		set_O t_images;
		Mat canvasToShow;
		IplImage img;
		bool doUpdate;
	public:
		Scene();
		virtual ~Scene();
		virtual void update();
		void mouseEvent(int event, int x, int y, int flags, void* param);
		void addObject(Object*);
		void removeObject(Object*);
		void pause();
		void goOn();
	};
}