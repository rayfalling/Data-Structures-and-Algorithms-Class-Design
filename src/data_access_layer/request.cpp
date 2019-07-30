#include "request.h"

namespace data_access_layer{
    nlohmann::json process_request(std::string& body){
        auto j = nlohmann::json::parse(body);
        return j;
    }
}
