#include "handlers.hpp"

namespace http_handlers{
	void handlers::registry_router(server::http_server* server) {
		server->add_handler("/api/login", account::login);
		server->add_handler("/api/registry", account::registry);
		server->add_handler("/api/logout", account::logout);
	}
} // namespace httpHandlers
