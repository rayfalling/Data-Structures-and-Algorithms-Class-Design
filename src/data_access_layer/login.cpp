#include "login.h"

namespace data_access_layer{
	void to_json(nlohmann::json& j, const login& account) {
		j = nlohmann::json{
			{"email", account.email}, {"password", account.password}
		};
	}

	void from_json(const nlohmann::json& j, login& account) {
		if (!j["email"].is_null()) 
			account.email = j.at("email").get<std::string>();
		if (!j["password"].is_null()) 
			account.password = j.at("password").get<std::string>();
	}
}
