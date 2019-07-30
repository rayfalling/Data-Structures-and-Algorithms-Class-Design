#pragma once
#include <string>
#include "../httpServer/http_server.hpp"
#include "../data_access_layer/hijeck.h"

struct mg_connection;

namespace http_handlers{
	class display {
	public:
		static bool display_advertisement(std::string url, std::string body,
		                  std::string method, mg_connection* c,
		                  OnRspCallback rsp_callback);
		static bool display_listing(std::string url, std::string body,
		                     std::string method, mg_connection* c,
		                     OnRspCallback rsp_callback);
		static bool logout(std::string url, std::string body,
		                   std::string method, mg_connection* c,
		                   OnRspCallback rsp_callback);
	};
}
