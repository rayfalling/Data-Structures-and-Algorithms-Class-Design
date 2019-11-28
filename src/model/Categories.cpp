#include "Categories.h"

namespace model{

	const int categories::top_level = 0;
	const int categories::no_parent = -1;

	category* categories::operator[](const int& number) {
		for (auto it = objects_.begin(); it != objects_.end(); ++it) {
			if ((*it)->get_number() == number) return *it;
		}
		return nullptr;
	}

	void categories::add(category* ptr) { objects_.push_back(ptr); }

	categories::iterator categories::begin() { return objects_.begin(); }

	categories::iterator categories::end() { return objects_.end(); }

	std::vector<category*> categories::get_container(){
		return this->objects_;
	}
}
