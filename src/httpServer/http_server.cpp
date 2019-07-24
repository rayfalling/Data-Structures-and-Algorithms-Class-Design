#include "http_server.hpp"
#include <iostream>
#include <utility>

std::string server::http_server::s_web_dir = "./webroot";
std::unordered_map<std::string, ReqHandler> server::http_server::s_handler_map;
std::unordered_set<mg_connection *> server::http_server::s_websocket_session_set;

server::http_server::~http_server() = default;

void server::http_server::init(const std::string& port) {
	m_port = port;
	s_server_option.enable_directory_listing = "no";
	s_server_option.document_root = s_web_dir.c_str();
	// 开启 CORS，本项只针对主页加载有效
	s_server_option.extra_headers = "Access-Control-Allow-Origin: *";
}

bool server::http_server::start() {
	mg_mgr_init(&m_mgr, nullptr);
	mg_connection* connection =
		mg_bind(&m_mgr, m_port.c_str(), on_http_websocket_event);
	if (connection == nullptr) return false;
	// for both http and websocket
	mg_set_protocol_http_websocket(connection);

	printf("starting http server at port: %s\n", m_port.c_str());
	// loop
	while (true)
		mg_mgr_poll(&m_mgr, 500); // ms
}

void server::http_server::on_http_websocket_event(mg_connection* connection, int event_type,
                                               void* event_data) {
	// 区分http和websocket
	if (event_type == MG_EV_HTTP_REQUEST) {
		const auto http_req = static_cast<http_message *>(event_data);
		handle_http_event(connection, http_req);
	}
	else if (event_type == MG_EV_WEBSOCKET_HANDSHAKE_DONE ||
		event_type == MG_EV_WEBSOCKET_FRAME ||
		event_type == MG_EV_CLOSE) {
		websocket_message* ws_message =
			static_cast<struct websocket_message *>(event_data);
		handle_websocket_message(connection, event_type, ws_message);
	}
}

// ---- simple http ---- //
static bool route_check(http_message* http_msg, char* route_prefix,
                        std::string method) {
	return mg_vcmp(&http_msg->uri, route_prefix) == 0;
}

void server::http_server::add_handler(const std::string& url, ReqHandler req_handler) {
	if (s_handler_map.find(url) != s_handler_map.end()) return;

	s_handler_map.insert(std::make_pair(url, req_handler));
}

void server::http_server::remove_handler(const std::string& url) {
	auto it = s_handler_map.find(url);
	if (it != s_handler_map.end()) s_handler_map.erase(it);
}

void server::http_server::send_http_rsp(mg_connection* connection, std::string rsp) {
	mg_printf(connection,
	          "HTTP/1.1 200 OK\r\n"
	          "Content-Type: application/json; charset=UTF-8\n"
	          "Cache-Control: no-cache\n"
	          "Content-Length: %d\n"
	          "Access-Control-Allow-Origin: *\n\n"
	          "%s\n",
	          rsp.length(), rsp.c_str());
}

void server::http_server::handle_http_event(mg_connection* connection,
                                          http_message* http_req) {
	std::string req_str =
		std::string(http_req->message.p, http_req->message.len);
	printf("got request: %s\n", req_str.c_str());

	std::string url = std::string(http_req->uri.p, http_req->uri.len);
	std::string body = std::string(http_req->body.p, http_req->body.len);
	std::string method = std::string(http_req->method.p, http_req->method.len);
	auto it = s_handler_map.find(url);
	if (it != s_handler_map.end()) {
		const ReqHandler handle_func = it->second;
		handle_func(url, body, method, connection, &http_server::send_http_rsp);
	}

	mg_serve_http(connection, http_req, s_server_option);
}

// ---- websocket ---- //
int server::http_server::is_websocket(const mg_connection* connection) {
	return connection->flags & MG_F_IS_WEBSOCKET;
}

void server::http_server::handle_websocket_message(mg_connection* connection,
                                                 int event_type,
                                                 websocket_message* ws_msg) {
	if (event_type == MG_EV_WEBSOCKET_HANDSHAKE_DONE) {
		printf("client websocket connected\n");
		// 获取连接客户端的IP和端口
		char addr[32];
		mg_sock_addr_to_str(&connection->sa, addr, sizeof(addr),
		                    MG_SOCK_STRINGIFY_IP | MG_SOCK_STRINGIFY_PORT);
		printf("client addr: %s\n", addr);

		// 添加 session
		s_websocket_session_set.insert(connection);

		send_websocket_msg(connection, "client websocket connected");
	}
	else if (event_type == MG_EV_WEBSOCKET_FRAME) {
		mg_str received_msg = {reinterpret_cast<char *>(ws_msg->data), ws_msg->size};

		char buff[1024] = {0};
		strncpy(
			buff, received_msg.p,
			received_msg
			.len); // must use strncpy, specifiy memory pointer and length

		// do sth to process request
		printf("received msg: %s\n", buff);
		send_websocket_msg(connection,
		                 "send your msg back: " + std::string(buff));
		// BroadcastWebsocketMsg("broadcast msg: " + std::string(buff));
	}
	else if (event_type == MG_EV_CLOSE) {
		if (is_websocket(connection)) {
			printf("client websocket closed\n");
			// 移除session
			if (s_websocket_session_set.find(connection) !=
				s_websocket_session_set.end())
				s_websocket_session_set.erase(connection);
		}
	}
}

void server::http_server::send_websocket_msg(mg_connection* connection, std::string msg) {
	mg_send_websocket_frame(connection, WEBSOCKET_OP_TEXT, msg.c_str(),
	                        strlen(msg.c_str()));
}

void server::http_server::broadcast_websocket_msg(std::string msg) {
	for (mg_connection* connection : s_websocket_session_set)
		mg_send_websocket_frame(connection, WEBSOCKET_OP_TEXT, msg.c_str(),
		                        strlen(msg.c_str()));
}

bool server::http_server::close() {
	mg_mgr_free(&m_mgr);
	return true;
}
