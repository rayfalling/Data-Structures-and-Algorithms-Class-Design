#pragma once

#include "mongoose.h"
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>

//Ĭ����ӦͷΪapplication/json; charset=UTF-8

// ����http����callback
typedef void OnRspCallback(mg_connection* c, std::string);
// ����http����handler
using ReqHandler = std::function<bool(std::string, std::string, std::string,
                                      mg_connection* c, OnRspCallback)>;

namespace server{
	class http_server {
	public:
		http_server() = default;

		~http_server();
		void init(const std::string& port); // ��ʼ������
		bool start(); // ����httpserver
		bool close(); // �ر�
		void add_handler(const std::string& url,
		                ReqHandler req_handler); // ע���¼�������
		void remove_handler(const std::string& url); // �Ƴ�ʱ�䴦����
		static std::string s_web_dir; // ��ҳ��Ŀ¼
		static mg_serve_http_opts s_server_option; // web������ѡ��
		static std::unordered_map<std::string, ReqHandler>
		s_handler_map; // �ص�����ӳ���

	private:
		// ��̬�¼���Ӧ����
		static void on_http_websocket_event(mg_connection* connection, int event_type,
		                                 void* event_data);

		static void handle_http_event(mg_connection* connection,
		                            http_message* http_req);
		static void send_http_rsp(mg_connection* connection, std::string rsp);

		static int is_websocket(
			const mg_connection* connection); // �ж��Ƿ���websoket��������
		static auto handle_websocket_message(mg_connection* connection,
		                                   int event_type,
		                                   websocket_message* ws_msg) -> void;
		static void send_websocket_msg(mg_connection* connection,
		                             std::string msg); // ������Ϣ��ָ������
		static void broadcast_websocket_msg(std::string msg); // ���������ӹ㲥��Ϣ
		static std::unordered_set<mg_connection*>
		s_websocket_session_set; // ����websocket����

		std::string m_port; // �˿�
		mg_mgr m_mgr{}; // ���ӹ�����
	};
}
