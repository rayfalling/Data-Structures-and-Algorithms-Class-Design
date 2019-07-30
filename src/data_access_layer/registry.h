#pragma once
#include "../model/Client.h"
#include "../json/json.hpp"
#include <string>

namespace data_access_layer{

	struct registry {
		string email;
		string password;
		string password_verify;
		string firstname;
		string lastname;

		explicit operator model::client() const;
	};

	void to_json(nlohmann::json& j, const registry& account);

	void from_json(const nlohmann::json& j, registry& account);
}
