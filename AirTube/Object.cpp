#include"Object.h"
namespace GameUnit {
	Object::Object() {
		depth = 0;
	}
	bool Object::Compare::operator()(const Object_ptr&a, const Object_ptr&b)const{
		return a->depth > b->depth;
	}
}