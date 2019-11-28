#pragma once

#include "json.hpp"
#include <string>
#include <vector>

template <typename T>
class json_helper {
public:
	static std::string get_string_from_class(T);
	static T parse_json_string(std::string json);
};

template <typename T>
std::string json_helper<T>::get_string_from_class(T data) {
	const nlohmann::json j = data;
	return j.dump();
}

template <typename T>
T json_helper<T>::parse_json_string(const std::string json) {
	auto json_object = nlohmann::json::parse(json);
	return json_object;
}
