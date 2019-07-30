#pragma once
#include "../json/json.hpp"
#include <string>

namespace data_access_layer {
    nlohmann::json process_request(std::string &body);
    nlohmann::json process_url(std::string &url);
}