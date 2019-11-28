#pragma once
#include <vector>

#include "Category.h"

namespace model{
	class categories final {

	protected:
		typedef std::vector<category*> container;

	public:
		~categories() = default;
		typedef container::iterator iterator;

	protected:
		container objects_;

	public:
		static const int top_level;
		static const int no_parent;

		category* operator[](const int& number);
		void add(category* ptr);

		std::vector<category*> get_container();

		iterator begin();
		iterator end();

	};
}
