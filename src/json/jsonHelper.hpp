#pragma once

#include "json.hpp"
#include <string>

using nlohmann::json;

template <typename T>
class jsonHelper {
public:
	static std::string get_string_from_class(T);
	static T parse_json_string(std::string json);
};

template <typename T>
std::string jsonHelper<T>::get_string_from_class(T data) {
	json j = data;
	return j.dump();
}

template <typename T>
T jsonHelper<T>::parse_json_string(std::string json) {
	auto json_object = json::parse(json);
	return json_object;
}

