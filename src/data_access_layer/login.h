#pragma once
#include <string>
#include "../json/json.hpp"

namespace data_access_layer {
	struct login {
		std::string email;
		std::string password;
	};

	void to_json(nlohmann::json& j, const login& account);

	void from_json(const nlohmann::json& j, login& account);
}
