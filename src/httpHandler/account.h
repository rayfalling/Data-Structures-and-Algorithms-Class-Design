#pragma once
#include "../httpServer/http_server.hpp"

namespace http_handlers{
	class account {
	public:
		static bool login(const std::string& url, std::string body,
		                  std::string method, mg_connection* c,
		                  OnRspCallback rsp_callback);
		static bool registry(const std::string& url, std::string body,
		                     std::string method, mg_connection* c,
		                     OnRspCallback rsp_callback);
		static bool logout(const std::string& url, const std::string& body,
		                   std::string method, mg_connection* c,
		                   OnRspCallback rsp_callback);
	};
}
