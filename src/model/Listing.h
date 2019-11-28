#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
#include "Advertisement.h"

namespace model{
	class listing final {
		typedef std::vector<model::advertisement*> container;
	public:
		~listing();
		typedef container::iterator iterator;
	protected:
		container objects_;
	public:
		advertisement* operator[](const int& number);
		void add(advertisement* ptr);
		iterator begin();
		iterator end();
		std::vector<model::advertisement*> get_container();
		// return a sorted copy of this Listing
		listing sort(string field);
		// return a filtered by keyword copy of this Listing
		listing filter(string keyword);
	};
}
