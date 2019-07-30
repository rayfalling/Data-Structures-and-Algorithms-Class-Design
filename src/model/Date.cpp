#include "Date.h"
#include <iomanip>

namespace model{
	date::~date() = default;

	date::date() {
		this->year_ = 0;
		this->month_ = 0;
		this->day_ = 0;
		this->hour_ = 0;
		this->minute_ = 0;
		this->second_ = 0;
	}

	date::date(date const& date) {
		this->year_ = date.get_year();
		this->month_ = date.get_month();
		this->day_ = date.get_day();
		this->hour_ = date.get_hour();
		this->minute_ = date.get_minute();
		this->second_ = date.get_second();
	}

	date::date(const int month, const int day, const int year, const int hour, const int minute, const int second) {
		this->year_ = year;
		this->month_ = month;
		this->day_ = day;
		this->hour_ = hour;
		this->minute_ = minute;
		this->second_ = second;
	}

	void date::set_day(int& day) { this->day_ = day; }
	void date::set_hour(int& hour) { this->hour_ = hour; }
	void date::set_minute(int& minute) { this->minute_ = minute; }
	void date::set_month(int& month) { this->month_ = month; }
	void date::set_second(int& second) { this->second_ = second; }
	void date::set_year(int& year) { this->year_ = year; }

	int date::get_day() const { return this->day_; }
	int date::get_hour() const { return this->hour_; }
	int date::get_minute() const { return this->minute_; }
	int date::get_month() const { return this->month_; }
	int date::get_second() const { return this->second_; }
	int date::get_year() const { return this->year_; }

	bool date::operator==(const date& rhs) const {
		return rhs.get_year() == this->year_ && rhs.get_month() == this->month_ &&
			rhs.get_day() == this->day_ && rhs.get_hour() == this->hour_ &&
			rhs.get_minute() == this->minute_ && rhs.get_second() == this->second_;
	}

	bool date::operator<(const date& rhs) const {
		if (this->year_ < rhs.get_year()) return true;
		if (this->year_ == rhs.get_year()) {
			if (this->month_ < rhs.get_month()) return true;
			if (this->month_ == rhs.get_month()) {
				if (this->day_ < rhs.get_day()) return true;
				if (this->day_ == rhs.get_day()) {
					if (this->hour_ < rhs.get_hour()) return true;
					if (this->hour_ == rhs.get_hour()) {
						if (this->minute_ < rhs.get_minute()) return true;
						if (this->minute_ == rhs.get_minute()) {
							if (this->second_ < rhs.get_second()) return true;
						}
					}
				}
			}
		}
		return false;
	}

	std::ostream& operator<<(std::ostream& stream, const date& date) {
		stream << std::setfill('0') << std::setw(2) << date.get_month() << '/' << date.get_day()
			<< '/' << std::setw(4) << date.get_year() << " " << std::setw(2)
			<< date.get_hour() << ":" << date.get_minute() << ":"
			<< date.get_second() << std::endl;

		return stream;
	}

	std::istream& operator>>(std::istream& stream, date& date) {
		char tmp;
		int day, month, year, hour, minute, second;
		stream >> month >> tmp >> day >> tmp >> year >> hour >> tmp >> minute >>
			tmp >> second;
		date.set_day(day);
		date.set_month(month);
		date.set_year(year);
		date.set_hour(hour);
		date.set_minute(minute);
		date.set_second(second);

		return stream;
	}
}
