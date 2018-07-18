#pragma once
#include"Object.h"
#include<set>
namespace GameUnit {
	class Scene {
	private:
		std::set<Object*,Object::Compare>images;
		bool doUpdate;
		cv::Mat canvasToShow;
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