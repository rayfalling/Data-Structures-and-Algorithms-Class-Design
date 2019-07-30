#include "advertisement_access.h"
#include "../model/Date.h"

namespace data_access_layer{
	void to_json(nlohmann::json& j, const advertisement_access& adv) {
		j = nlohmann::json{};
	}

	void from_json(const nlohmann::json& j, advertisement_access& adv) {
		
	}
}