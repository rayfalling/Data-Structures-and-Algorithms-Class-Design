#pragma once
#include "../httpServer/http_server.hpp"
#include <string>

namespace http_handlers{
	class handlers {
	public:
		static void registry_router(server::http_server* server);
	private:
		static bool login(std::string url, std::string body,
		                  std::string method, mg_connection* c,
		                  OnRspCallback rsp_callback);
		static bool registry(std::string url, std::string body,
		                     std::string method, mg_connection* c,
		                     OnRspCallback rsp_callback);
	};
} // namespace httpHandlers
