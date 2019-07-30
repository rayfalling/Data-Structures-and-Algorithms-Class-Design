#include "Listing.h"

namespace model{
	listing::~listing() = default;

	advertisement* listing::operator[](const int& number) {
		for (auto it = objects_.begin(); it != objects_.end(); ++it) {
			if ((*it)->get_number() == number) return (*it);
		}
		return nullptr;
	}

	void listing::add(advertisement* ptr) { objects_.push_back(ptr); }

	listing::iterator listing::begin() { return objects_.begin(); }

	listing::iterator listing::end() { return objects_.end(); }
}
