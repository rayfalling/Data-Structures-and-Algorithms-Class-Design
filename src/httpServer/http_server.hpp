#pragma once

#include "mongoose.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>

//默认响应头为application/json; charset=UTF-8

// 定义http返回callback
typedef void OnRspCallback(mg_connection* c, std::string);
// 定义http请求handler
using ReqHandler = std::function<bool(std::string, std::string, std::string,
                                      mg_connection* c, OnRspCallback)>;

namespace server{
	class http_server {
	public:
		http_server() = default;

		~http_server();
		void init(const std::string& port); // 初始化设置
		bool start(); // 启动httpserver
		bool close(); // 关闭
		void add_handler(const std::string& url,
		                ReqHandler req_handler); // 注册事件处理函数
		void remove_handler(const std::string& url); // 移除时间处理函数
		static std::string s_web_dir; // 网页根目录
		static mg_serve_http_opts s_server_option; // web服务器选项
		static std::unordered_map<std::string, ReqHandler>
		s_handler_map; // 回调函数映射表

	private:
		// 静态事件响应函数
		static void on_http_websocket_event(mg_connection* connection, int event_type,
		                                 void* event_data);

		static void handle_http_event(mg_connection* connection,
		                            http_message* http_req);
		static void send_http_rsp(mg_connection* connection, std::string rsp);

		static int is_websocket(
			const mg_connection* connection); // 判断是否是websoket类型连接
		static auto handle_websocket_message(mg_connection* connection,
		                                   int event_type,
		                                   websocket_message* ws_msg) -> void;
		static void send_websocket_msg(mg_connection* connection,
		                             std::string msg); // 发送消息到指定连接
		static void broadcast_websocket_msg(std::string msg); // 给所有连接广播消息
		static std::unordered_set<mg_connection*>
		s_websocket_session_set; // 缓存websocket连接

		std::string m_port; // 端口
		mg_mgr m_mgr{}; // 连接管理器
	};
}
