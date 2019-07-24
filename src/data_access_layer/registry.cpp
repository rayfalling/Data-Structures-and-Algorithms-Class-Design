#include "../data_access_layer/registry.h"

namespace data_access_layer{
	registry::operator model::client() const {
		auto email_local = email, firstname_local = firstname, lastname_local = lastname, password_local = password;
		return model::client(firstname_local, lastname_local, email_local, password_local);
	}

	void to_json(nlohmann::json& j, const registry& account) {
		j = nlohmann::json{
			{"email", account.email}, {"firstname", account.firstname}, {"lastname", account.lastname},
			{"password", account.password}
		};
	}

	void from_json(const nlohmann::json& j, registry& account) {
		account.email = j.at("email").get<std::string>();
		account.firstname = j.at("firstname").get<std::string>();
		account.lastname = j.at("lastname").get<std::string>();
		account.password = j.at("password").get<std::string>();
		account.password_verify = j.at("password_verify").get<std::string>();
	}

}
