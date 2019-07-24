#pragma once
#include <vector>

#include "Advertisement.h"

using namespace std;

class listing final {

protected:
	typedef vector<advertisement*> Container;

public:
	~listing();
	typedef Container::iterator iterator;

protected:
	Container objects;

public:
	advertisement* operator[](const int& number);

	void add(advertisement* ptr);

	iterator begin();
	iterator end();

};
