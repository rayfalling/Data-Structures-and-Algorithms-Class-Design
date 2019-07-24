#include "main.hpp"
#include "model/GlobalSettings.h"
using namespace std;

// 初始化HttpServer静态类成员
mg_serve_http_opts server::http_server::s_server_option;
using handlers = http_handlers::handlers;

int main(int argc, char* argv[]) {
	const string port = "8081";
	shared_ptr<server::http_server> http_server = make_shared<server::http_server>();
	http_server->init(port);
	handlers::registry_router(http_server.get());
	http_server->start();
	return 0;
}
