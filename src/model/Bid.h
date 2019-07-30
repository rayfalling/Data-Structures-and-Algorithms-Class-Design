#pragma once
#include "Date.h"
#include <string>
using string = std::string;
namespace model{
	class bid final {
		string email_;
		float amount_;
		int quantity_;
		date date_;

	public:
		~bid();
		bid();
		bid(const bid& b);
		bid(string email, float amount, int quantity, date& date);

		[[nodiscard]] string get_email() const;
		[[nodiscard]] float get_amount() const;
		[[nodiscard]] int get_quantity() const;
		[[nodiscard]] date get_date() const;

		void set_email(const string&);
		void set_amount(const float&);
		void set_quantity(const int&);
		void set_date(const date&);

		bool operator<(const bid& rhs) const;
		bool operator==(const bid& rhs) const;
	};

	std::istream& operator>>(std::istream& stream, bid& b);

}
