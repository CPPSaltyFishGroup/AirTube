#include"Object.h"
namespace GameUnit {
	Object::Object() {
		depth = 0;
	}
	bool Object::Compare::operator()(const Object*&a, const Object*&b)const{
		return a->depth > b->depth;
	}
}