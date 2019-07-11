#pragma once

#include "../json/json.hpp"
#include <string>

using nlohmann::json;
//命名空间下添加新类需要添加对应的to_json和from_json函数
namespace implemention {
class BaseClass {
  private:
  public:
	int			a = 0;
	std::string b = "123";
	BaseClass();
};
void to_json(json &j, const BaseClass &base);

void from_json(const json &j, BaseClass &base);
} // namespace implemention
