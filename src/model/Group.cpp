#include "Group.h"

model::client* group::operator[](const string& email) {
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		if ((*it)->get_email() == email) return *it;
	}
	return nullptr;
}

void group::add(model::client* ptr) { objects.push_back(ptr); }

group::iterator group::begin() { return objects.begin(); }

group::iterator group::end() { return objects.end(); }
