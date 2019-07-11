#include "main.hpp"

using namespace std;

// 初始化HttpServer静态类成员
mg_serve_http_opts HttpServer::s_server_option;
using handlers = httpHandlers::handlers;

int main(int argc, char *argv[]) {
	const string port = "8081";
	auto		 http_server = std::make_shared<HttpServer>();
	http_server->Init(port);
	handlers::RegeristRouter(http_server.get());
	http_server->Start();
	return 0;
}
