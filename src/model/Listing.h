#pragma once
#include <vector>

#include "Advertisement.h"
namespace model{
	class listing final {
	protected:
		typedef std::vector<advertisement*> container;
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
	};
}
