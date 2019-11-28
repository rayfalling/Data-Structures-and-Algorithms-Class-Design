#include "Listing.h"
#include <algorithm>

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

	std::vector<model::advertisement*> listing::get_container(){
		return this->objects_;
	}

	// return a sorted copy of this Listing
	listing listing::sort(string field) {        
		listing *list = new listing();
		for_each(this->begin(), this->end(), [&](advertisement *adv) { list->add(adv); });
		std::sort(list->begin(), list->end(),         
				[&](advertisement *a, advertisement *b) {
					if (field == "email") {
						return a->get_email() < b->get_email();
					}
					if (field == "start") {
						return a->get_start() < b->get_start();
					}
					if (field == "close") {
						return a->get_close() < b->get_close();
					}
					if (field == "quantity") {
						return a->get_quantity() < b->get_quantity();
					}
					if (field == "highest") {
						if (a->get_bids().empty() || b->get_bids().empty())
							return false;
						return a->get_bids().top().get_amount() >
								b->get_bids().top().get_amount();
					}
					if (field == "lowest") {
						if (a->get_bids().empty() || b->get_bids().empty())
							return false;
						return a->get_bids().top().get_amount() <
								b->get_bids().top().get_amount();
					}
					return false;
				});

		return (*list);
	}

	// return a filtered by keyword copy of this Listing
	listing listing::filter(string keyword) {
		listing *list = new listing();
		for_each(this->begin(), this->end(), [&](advertisement *adv) {
			if (adv->get_body().find(keyword, 0) == string::npos &&
				adv->get_title().find(keyword, 0) == string::npos) {
				return;
			}
			list->add(adv);
		});

		return (*list);
	}
}