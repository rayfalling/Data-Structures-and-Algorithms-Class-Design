#pragma once
#include <string>
#include "../httpServer/http_server.hpp"
#include "../data_access_layer/hijeck.h"

struct mg_connection;

namespace http_handlers{
	class display {
	public:
		static bool request_list(std::string url, std::string body,
		                  std::string method, mg_connection* c,
		                  OnRspCallback rsp_callback);
		static bool request_list_sorted(std::string url, std::string body,
		                     std::string method, mg_connection* c,
		                     OnRspCallback rsp_callback);
		static bool request_list_filter(std::string url, std::string body,
		                   std::string method, mg_connection* c,
		                   OnRspCallback rsp_callback);
		static bool add_advertisement(std::string url, std::string body,
		                   std::string method, mg_connection* c,
		                   OnRspCallback rsp_callback);
	};
}
