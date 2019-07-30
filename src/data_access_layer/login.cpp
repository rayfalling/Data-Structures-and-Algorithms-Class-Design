#include "login.h"

namespace data_access_layer{
	void to_json(nlohmann::json& j, const login& account) {
		j = nlohmann::json{
			{"email", account.email}, {"password", account.password}
		};
	}

	void from_json(const nlohmann::json& j, login& account) {
		account.email = j.at("email").get<std::string>();
		account.password = j.at("password").get<std::string>();
	}
}
