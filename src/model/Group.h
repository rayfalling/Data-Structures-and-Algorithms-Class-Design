#pragma once
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

#include "Client.h"

using namespace std;

class group {

protected:
	typedef vector<model::client*> Container;

public:
	virtual ~group() = default;
	typedef Container::iterator iterator;

protected:
	Container objects;

public:
	model::client* operator[](const string& email);

	virtual void add(model::client* ptr);

	virtual iterator begin();
	virtual iterator end();

};
