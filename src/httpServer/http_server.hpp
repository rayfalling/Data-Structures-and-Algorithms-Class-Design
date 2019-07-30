#pragma once

#include "mongoose.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>

typedef void OnRspCallback(mg_connection *c, std::string);
using req_handler = std::function<bool(std::string, std::string, std::string,
									   mg_connection *c, OnRspCallback)>;

namespace server {
class http_server {
  public:
	http_server() = default;

	~http_server();
	void init(const std::string &port);
	bool start();
	bool close();
	void add_handler(const std::string &url, req_handler req_handler);
	void remove_handler(const std::string &url);
	static std::string									s_web_dir;
	static mg_serve_http_opts							s_server_option;
	static std::unordered_map<std::string, req_handler> s_handler_map;

  private:
	static void on_http_websocket_event(mg_connection *connection,
										int event_type, void *event_data);
	static void handle_http_event(mg_connection *connection,
								  http_message * http_req);
	static void send_http_rsp(mg_connection *connection, std::string rsp);
	static int  is_websocket(const mg_connection *connection);
	static void handle_websocket_message(mg_connection *connection, int event_type, websocket_message *ws_msg);
	static void send_websocket_msg(mg_connection *connection, std::string msg);
	static void broadcast_websocket_msg(std::string msg);
	static std::unordered_set<mg_connection *> s_websocket_session_set_;
	std::string								   m_port;
	mg_mgr									   m_mgr{};
};
} // namespace server
