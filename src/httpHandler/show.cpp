#include "show.h"
#include "../data_access_layer/request.h"

namespace http_handlers{
	bool display::display_advertisement(std::string url, std::string body, std::string method,
	                                    mg_connection* c, OnRspCallback rsp_callback) {
			auto json = data_access_layer::process_request(body);
			
		return true;
	}
}
