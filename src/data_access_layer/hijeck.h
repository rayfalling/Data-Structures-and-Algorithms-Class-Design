#pragma once
#include "../model/Advertisement.h"
#include "../model/Date.h"
#include "../model/Listing.h"
#include "../json/json.hpp"

//hijeck to model::date serializer
namespace model{
	void to_json(nlohmann::json& j, const model::date& date);

	void from_json(const nlohmann::json& j, model::date& date);
}

//hijeck to model::advertisement serializer
namespace model{
	void to_json(nlohmann::json& j, const model::advertisement& adv);

	void from_json(const nlohmann::json& j, model::advertisement& adv);
}

//hijeck to model::listing serializer
namespace model{
	void to_json(nlohmann::json& j, const model::listing& adv_list);

	void from_json(const nlohmann::json& j, model::listing& adv_list);
}