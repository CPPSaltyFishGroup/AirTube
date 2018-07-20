#include"Scene.h"
#include"Tools.h"
#include"MainGameRunner.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
typedef std::set<GameUnit::Object*, GameUnit::Object::Compare> set_O;
namespace GameUnit {
	using Tools::clamp;
	using cv::Scalar;

	Scene::Scene() {
		doUpdate = true;
		canvasToShow = Mat(640, 800, CV_8UC3, Scalar(255, 255, 255));
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
		//************************
		//canvas.copyTo(canvasToShow);
		cvSet(&img, Scalar::all(255), nullptr);
		//canvasToShow= Mat(640, 800, CV_8UC3, Scalar(255, 255, 255));
		//cvSet((void*)&canvasToShow, Scalar::all(255), nullptr);
		for (set_O::iterator it = images.begin(); it != images.end(); ++it) {
			(*it)->update();
			(*it)->print(canvasToShow);
		}
		imshow(MainGameRunner::getMainGameRunner()->gameName, canvasToShow);
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