#include"Scene.h"
#include"ToggleObject.h"
#include"Tools.h"
#include"MainGameRunner.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
namespace View{
	typedef std::set<Object*, Object::Compare> set_O;
	using Tools::clamp;
	using cv::Scalar;

	Scene::Scene() {
		doUpdate = true;
		canvasToShow = Mat(640, 800, CV_8UC3, Scalar(255,255,255));
		img = IplImage(canvasToShow);
		//canvas.cols = 800;
		//canvas.rows = 640;//could use file reading
	}
	Scene::~Scene() {
		//who new,who delete. but it doesn't work here
		for (set_O::iterator it = images.begin(); it != images.end(); ) {
			set_O::iterator tt = it++;
			delete *tt;
		}
	}

	//do update,then print.
	void Scene::update() {
		if (!doUpdate)
			return;
		using namespace cv;
		cvSet(&img, Scalar(255,255,255), nullptr);
		//(*images.begin())->print(canvasToShow);
		for (set_O::iterator it = images.begin(); it != images.end(); ++it)
			(*it)->print(canvasToShow);
		imshow(MainGameRunner::getMainGameRunner()->gameName, canvasToShow);
	}

	void Scene::mouseEvent(int event, int x, int y, int flags, void* param) {
		if (event == CV_EVENT_MOUSEMOVE) {
			for (set_O::iterator it = t_images.begin(); it != t_images.end(); ++it) {
				bool&flag = dynamic_cast<ToggleObject*>(*it)->flag;
				if ((*it)->mouseIn(Point(x, y)))
					flag = true;
				else if (flag == true)
					flag = false;
			}
		}
		else if (event == CV_EVENT_LBUTTONDOWN || event == CV_EVENT_RBUTTONDOWN) {
			for (set_O::iterator it = t_images.begin(); it != t_images.end(); ++it) {
				if ((*it)->mouseIn(Point(x, y))) {
					dynamic_cast<PictureObject*>(*it)->onClick(event == CV_EVENT_LBUTTONDOWN);
					return;
				}
			}
		}
	}

	void Scene::addObject(Object*object) {
		images.insert(object);
		int attr = object->getAttribute();
		if (attr & 10)
			c_images.insert(object);
		if (attr & 1)
			t_images.insert(object);
	}
	//warning, the function wouldn't free the memory of object
	void Scene::removeObject(Object*object) {
		images.erase(object);
		int attr = object->getAttribute();
		if (attr & 10)
			c_images.erase(object);
		if (attr & 1)
			t_images.erase(object);
	}
	void Scene::pause() {
		doUpdate = false;
	}
	void Scene::goOn() {
		doUpdate = true;
	}
}