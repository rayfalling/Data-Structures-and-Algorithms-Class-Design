#pragma once
#include <ostream>
#include "../json/json.hpp"

using namespace std;

namespace model{
	class date final {
		int month_;
		int day_;
		int year_;
		int hour_;
		int minute_;
		int second_;

	public:
		~date();
		date();
		date(date const&);
		date(int month, int day, int year, int hour, int minute, int second);

		void set_month(int&);
		void set_day(int&);
		void set_year(int&);
		void set_hour(int&);
		void set_minute(int&);
		void set_second(int&);

		[[nodiscard]] int get_month() const;
		[[nodiscard]] int get_day() const;
		[[nodiscard]] int get_year() const;
		[[nodiscard]] int get_hour() const;
		[[nodiscard]] int get_minute() const;
		[[nodiscard]] int get_second() const;

		bool operator==(const date& rhs) const;
		bool operator<(const date& rhs) const;

	};

	ostream& operator<<(ostream&, const date&);
	istream& operator>>(istream&, date&);

	void to_json(nlohmann::json& j, const date& date);

	void from_json(const nlohmann::json& j, date& date);
}
