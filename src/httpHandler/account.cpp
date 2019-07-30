#include "account.h"
#include "../model/Client.h"
#include "../model/GlobalSettings.h"
#include "../data_access_layer/login.h"
#include "../json/jsonHelper.hpp"
#include "../data_access_layer/registry.h"

namespace http_handlers{
	bool account::registry(const std::string&, std::string body, std::string method, mg_connection* c,
	                       OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
		const auto json_object = json_helper<data_access_layer::registry>::parse_json_string(std::move(body));
		auto verify = json_object.password_verify;
		auto client = static_cast<model::client>(json_object);
		/*
		 * Check for existing user
		 */
		const auto search_results = users[client.get_email()];
		if ((client.verify_password(verify)) && (search_results == nullptr)) {
			active_user = client.get_email();
			auto* new_client = new model::client(client);
			users.add(new_client);
			create_verified = true;
		} else {
			create_verified = false;
		}
		const nlohmann::json response = {{"status", create_verified}};
		rsp_callback(c, response.dump());
		return true;
	}

	bool account::logout(const std::string&, const std::string&, std::string method, mg_connection* c,
	                     OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
		active_user = "";
		const nlohmann::json response = {{"status", true}};
		rsp_callback(c, response.dump());
		return true;
	}

	bool account::login(const std::string&, std::string body, std::string method, mg_connection* c,
	                    OnRspCallback rsp_callback) {
		transform(method.begin(), method.end(), method.begin(), tolower);
		if (method != "post")return false;
		const auto json_object = json_helper<data_access_layer::login>::parse_json_string(std::move(body));
		const auto search_results = users[json_object.email];
		auto password = json_object.password;
		if (search_results != nullptr) {
			if (search_results->verify_password(password)) {
				active_user = json_object.email;
				login_failed = false;
			} else {
				login_failed = true;
			}
		} else {
			login_failed = true;
		}
		const nlohmann::json response = {{"status", !login_failed}};

		rsp_callback(c, response.dump());
		return true;
	}
}
