#include "Listing.h"

listing::~listing() = default;

advertisement* listing::operator[](const int& number) {
	for (auto it = objects.begin(); it != objects.end(); ++it) {
		if ((*it)->getNumber() == number) return (*it);
	}
	return nullptr;
}

void listing::add(advertisement* ptr) { objects.push_back(ptr); }

listing::iterator listing::begin() { return objects.begin(); }

listing::iterator listing::end() { return objects.end(); }
