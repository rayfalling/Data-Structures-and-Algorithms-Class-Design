#include "handlers.hpp"

namespace http_handlers{
	void handlers::registry_router(server::http_server* server) {
		server->add_handler("/api/login", account::login);
		server->add_handler("/api/registry", account::registry);
		server->add_handler("/api/logout", account::logout);
		server->add_handler("/api/list", display::request_list);
		server->add_handler("/api/list/sort", display::request_list_sorted);
		server->add_handler("/api/list/filter", display::request_list_filter);
		server->add_handler("/api/list/add", display::add_advertisement);
	}
} // namespace httpHandlers
