#include"Scene.h"
#include"Tools.h"
typedef std::set<GameUnit::Object*, GameUnit::Object::Compare> set_O;
namespace GameUnit {
	using Tools::clamp;

	Scene::Scene() {
		doUpdate = true;
		canvas.cols = 800;
		canvas.rows = 600;//could use file reading
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
		Mat cache;
		for (set_O::iterator it = images.begin(); it != images.end(); ++it) {
			(*it)->update();
			(*it)->print(canvas);
		}
	}
	inline void Scene::addObject(Object*object) {
		images.insert(object);
	}
	//warning, the function wouldn't free the memory of object
	inline void Scene::removeObject(Object*object) {
		images.erase(object);
	}
	inline void Scene::pause() {
		doUpdate = false;
	}
	inline void Scene::goOn() {
		doUpdate = true;
	}
}