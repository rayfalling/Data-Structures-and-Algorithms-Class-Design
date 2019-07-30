#pragma once
#include "../model/Advertisement.h"
#include "../model/Date.h"
#include "../json/json.hpp"

namespace data_access_layer{
	class advertisement_access {
	public:
		model::advertisement advertisement;
	};

	void to_json(nlohmann::json& j, const advertisement_access& adv);
	
	void from_json(const nlohmann::json& j, advertisement_access& adv);
}

