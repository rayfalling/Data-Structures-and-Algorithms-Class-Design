#include "BaseClass.hpp"

namespace implemention {
BaseClass::BaseClass() {}
void to_json(json &j, const BaseClass &base) {
	j = json{{"a", base.a}, {"b", base.b}};
}

void from_json(const json &j, BaseClass &base) {
	j.at("a").get_to(base.a);
	j.at("b").get_to(base.b);
}
} // namespace implemention
