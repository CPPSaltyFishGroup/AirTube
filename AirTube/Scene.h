#pragma once
#include"Object.h"
#include<set>
namespace GameUnit {
	class Scene {
	private:
		std::set<Object*,Object::Compare>images;
		bool updateFlag;
	public:
		Scene();
		virtual ~Scene();
		void update();
		void mouseEvent(int event, int x, int y, int flags, void* param);
		void addObject(const Object*);
		void removeObject(const Object*);
		void pause();
		void goOn();
	};
}