#include "hijeck.h"


//hijeck to model::date serializer
void model::to_json(nlohmann::json& j, const model::date& date) {
	j = nlohmann::json{
		{"year", date.get_year()}, {"month", date.get_month()}, {"day", date.get_day()},
		{"hour", date.get_hour()}, {"minute", date.get_minute()}, {"second", date.get_second()}
	};
}

void model::from_json(const nlohmann::json& j, model::date& date) {
	if (!j["year"].is_null()) {
		auto year = j.at("year").get<int>();
		date.set_year(year);
	}
	if (!j["month"].is_null()) {
		auto month = j.at("month").get<int>();
		date.set_month(month);
	}
	if (!j["day"].is_null()) {
		auto day = j.at("day").get<int>();
		date.set_day(day);
	}
	if (!j["hour"].is_null()) {
		auto hour = j.at("hour").get<int>();
		date.set_hour(hour);
	}
	if (!j["minute"].is_null()) {
		auto minute = j.at("minute").get<int>();
		date.set_minute(minute);
	}
	if (!j["second"].is_null()) {
		auto second = j.at("second").get<int>();
		date.set_second(second);
	}
}

//hijeck to model::advertisement serializer
void model::to_json(nlohmann::json& j, const model::advertisement& adv){
	j = nlohmann::json{
		{"number", adv.get_number()}, {"quantity", adv.get_quantity()}, {"title", adv.get_title()},
		{"email", adv.get_email()}, {"body", adv.get_body()}, {"start", adv.get_start()}, 
		{"close", adv.get_close()}
	};
}

void model::from_json(const nlohmann::json& j, model::advertisement& adv){
if (!j["number"].is_null()) {
		auto number = j.at("number").get<int>();
		adv.set_number(number);
	}
	if (!j["quantity"].is_null()) {
		auto quantity = j.at("quantity").get<int>();
		adv.set_quantity(quantity);
	}
	if (!j["title"].is_null()) {
		auto title = j.at("title").get<std::string>();
		adv.set_title(title);
	}
	if (!j["email"].is_null()) {
		auto email = j.at("email").get<std::string>();
		adv.set_email(email);
	}
	if (!j["body"].is_null()) {
		auto body = j.at("body").get<std::string>();
		adv.set_body(body);
	}
	if (!j["start"].is_null()) {
		auto start = j.at("start").get<model::date>();
		adv.set_start(start);
	}
	if (!j["close"].is_null()) {
		auto close = j.at("close").get<model::date>();
		adv.set_close(close);
	}
}