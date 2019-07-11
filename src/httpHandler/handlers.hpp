#pragma once

#include "../httpServer/http_server.hpp"
#include "../implemention/BaseClass.hpp"
#include "../json/jsonHelper.hpp"
#include <iostream>
#include <string>

namespace httpHandlers {

//每个后台接口对应一个处理函数
class handlers {
  private:
	static bool handle_fun1(std::string url, std::string body,
							std::string method, mg_connection *c,
							OnRspCallback rsp_callback);

  public:
	static void RegeristRouter(HttpServer *);
};
} // namespace httpHandlers
