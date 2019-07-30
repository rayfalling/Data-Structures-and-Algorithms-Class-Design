#include "Group.h"

namespace model{
	client* group::operator[](const std::string& email) {
		for (auto it = objects_.begin(); it != objects_.end(); ++it) {
			if ((*it)->get_email() == email) return *it;
		}
		return nullptr;
	}

	void group::add(client* ptr) { objects_.push_back(ptr); }

	group::iterator group::begin() { return objects_.begin(); }

	group::iterator group::end() { return objects_.end(); }
}
