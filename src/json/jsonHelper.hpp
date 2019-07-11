#pragma once

#include "json.hpp"
#include <string>

using nlohmann::json;

template <typename T> class jsonHelper {
  public:
	static std::string get_string_from_class(T);
};

template <typename T> std::string jsonHelper<T>::get_string_from_class(T data) {
	json j = data;
	return j.dump();
}
