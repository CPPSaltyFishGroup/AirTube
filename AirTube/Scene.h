#pragma once
#include"Object.h"
#include<set>
namespace GameUnit {
	class Scene {
	private:
		std::set<Object*,Object::Compare>images;
		bool doUpdate;
		cv::Mat canvas;//draw everything on it
	public:
		Scene();
		virtual ~Scene();
		void update();
		virtual void mouseEvent(int event, int x, int y, int flags, void* param)=0;
		inline void addObject(Object*);
		inline void removeObject(Object*);
		inline void pause();
		inline void goOn();
	};
}