#pragma once
#include "../json/json.hpp"
#include "../model/Listing.h"
#include <iostream>
#include <string>

using string = std::string;
namespace data_access_layer{
	class advertisement_request {
	public:
		string sort_method = "";
		string filter_keyword = "";
	private:
		string sort_method_map_func(string& sort_method);
	public:
		model::listing get_sorted_list(string& sort_method);
		model::listing get_filter_list(string& keyword);
	};

	void to_json(nlohmann::json& j, const advertisement_request& adv);
	
	void from_json(const nlohmann::json& j, advertisement_request& adv);
}

