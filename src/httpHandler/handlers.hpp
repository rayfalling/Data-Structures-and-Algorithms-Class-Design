#pragma once
#include "../httpServer/http_server.hpp"
#include "account.h"
#include "show.h"

namespace http_handlers{
	class handlers {
	public:
		static void registry_router(server::http_server* server);
	};
} // namespace httpHandlers
