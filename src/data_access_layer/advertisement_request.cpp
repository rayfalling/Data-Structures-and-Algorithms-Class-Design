#include "advertisement_request.h"
#include "../model/Date.h"
#include "../model/GlobalSettings.h"
#include <string>

namespace data_access_layer{

	//map frontend datatable colnum name to listing::sort keyword
	std::string advertisement_request::sort_method_map_func(string& sort_method){
		if(sort_method == "name")
			return "title";
		if(sort_method == "poster")
			return "email";
		if(sort_method == "post_date")
			return "start";
		if(sort_method == "close_date")
			return "close";
		if(sort_method == "quantity")
			return "quantity";
		if(sort_method == "bid_asc")
			return "lowest";
		if(sort_method == "bid_desc")
			return "highest";
		return nullptr;
	} 

	model::listing advertisement_request::get_sorted_list(string& sort_method){
		return advertisements.sort(sort_method_map_func(sort_method));
	}

	model::listing advertisement_request::get_filter_list(string& keyword){
		return advertisements.filter(sort_method_map_func(keyword));
	}

	void to_json(nlohmann::json& j, const advertisement_request& adv) {
		j = nlohmann::json{
			{"sort_method",adv.sort_method},
			{"filter_keyword",adv.filter_keyword}
		};
	}

	void from_json(const nlohmann::json& j, advertisement_request& adv) {
		if (!j["sort_method"].is_null()) 
			adv.sort_method = j.at("sort_method").get<std::string>();
		if (!j["filter_keyword"].is_null()) 
			adv.sort_method = j.at("filter_keyword").get<std::string>();
	}
}