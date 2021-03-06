#include"Object.h"
namespace View {
	Object::Object(int depth, const Point&position):depth(depth),position(position) {}
	Object::~Object(){}
	bool Object::Compare::operator()(const Object_ptr&a, const Object_ptr&b)const {
		return a->depth > b->depth;
	}
	bool Object::InverseCompare::operator()(const Object_ptr&a, const Object_ptr&b)const {
		return a->depth < b->depth;
	}

	int Object::getAttribute() {
		return attribute;
	}
}