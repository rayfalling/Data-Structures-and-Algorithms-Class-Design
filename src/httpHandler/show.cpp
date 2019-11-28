#include "show.h"
#include <string>
#include "../json/jsonHelper.hpp"
#include "../model/GlobalSettings.h"
#include "../data_access_layer/advertisement_request.h"

namespace http_handlers{
	bool display::request_list(std::string url, std::string body, std::string method,
	                                    mg_connection* c, OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
	 	auto response = json_helper<model::listing>::get_string_from_class(advertisements);
		rsp_callback(c,response);
		return true;
	}

	bool display::request_list_sorted(std::string url, std::string body, std::string method,
	                                    mg_connection* c, OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
	 	auto json_object = json_helper<data_access_layer::advertisement_request>::parse_json_string(std::move(body));
		const std::string sort_method = json_object.sort_method; 
	 	auto response = json_helper<model::listing>::get_string_from_class(json_object.get_sorted_list(json_object.sort_method));
		rsp_callback(c,response);
		return true;
	}

	bool display::request_list_filter(std::string url, std::string body, std::string method,
	                                    mg_connection* c, OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
	 	auto json_object = json_helper<data_access_layer::advertisement_request>::parse_json_string(std::move(body));
		const std::string sort_method = json_object.sort_method; 
	 	auto response = json_helper<model::listing>::get_string_from_class(json_object.get_filter_list(json_object.filter_keyword));
		rsp_callback(c,response);
		return true;
	}

	bool display::add_advertisement(std::string url, std::string body, std::string method,
	                                    mg_connection* c, OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
	 	auto json_object = json_helper<model::advertisement>::parse_json_string(std::move(body));
		json_object.set_number(++advertisement_counter);
		advertisements.add(&json_object);
		const nlohmann::json response = {{"status", true}};
		rsp_callback(c,response);
		return true;
	}
}
