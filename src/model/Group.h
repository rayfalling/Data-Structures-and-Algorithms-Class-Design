#pragma once
#include <vector>

#include "Client.h"

namespace model{
	class group final {
	protected:
		typedef std::vector<client*> container;

	public:
		~group() = default;
		typedef container::iterator iterator;

	protected:
		container objects_;

	public:
		client* operator[](const std::string& email);

		void add(client* ptr);

		iterator begin();
		iterator end();

	};
}
