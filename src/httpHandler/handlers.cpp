#include "handlers.hpp"

using namespace std;

namespace httpHandlers {
bool handlers::handle_fun1(string url, string body, string method,
						   mg_connection *c, OnRspCallback rsp_callback) {
	// do sth
	cout << "handle fun1" << endl;
	cout << "url: " << url << endl;
	cout << "body: " << body << endl;
	auto t = implemention::BaseClass();

	rsp_callback(c,
				 jsonHelper<implemention::BaseClass>::get_string_from_class(t));

	return true;
}

void handlers::RegeristRouter(HttpServer *server) {
	server->AddHandler("/api/fun1", handlers::handle_fun1);
}
} // namespace httpHandlers
