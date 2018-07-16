#include"Scene.h"
#include"Tools.h"
#include"MainGameRunner.h"
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>
typedef std::set<GameUnit::Object*, GameUnit::Object::Compare> set_O;
namespace GameUnit {
	using Tools::clamp;

	Scene::Scene() {
		doUpdate = true;
		canvas = cv::imread("canvas.jpg");
		//canvas.cols = 800;
		//canvas.rows = 640;//could use file reading
	}
	Scene::~Scene() {
		for (set_O::iterator it = images.begin(); it != images.end(); ) {
			set_O::iterator tt = it++;
			delete *tt;
			images.erase(tt);
		}
	}

	//do update,then print.
	void Scene::update() {
		if (!doUpdate)
			return;
		using namespace cv;
		Mat canvasToShow;
		canvas.copyTo(canvasToShow);
		Mat cache;
		for (set_O::iterator it = images.begin(); it != images.end(); ++it) {
			(*it)->update();
			(*it)->print(canvasToShow);
		}
		imshow(MainGameRunner::getMainGameRunner()->gameName, canvasToShow);
	}
	void Scene::addObject(Object*object) {
		images.insert(object);
	}
	//warning, the function wouldn't free the memory of object
	void Scene::removeObject(Object*object) {
		images.erase(object);
	}
	void Scene::pause() {
		doUpdate = false;
	}
	void Scene::goOn() {
		doUpdate = true;
	}
}