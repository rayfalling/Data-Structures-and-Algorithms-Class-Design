#include "Bid.h"
#include <iostream>
#include <string>
namespace model{

	bid::~bid() = default;

	bid::bid() {
		this->email_ = "";
		this->amount_ = 0;
		this->quantity_ = 0;
		this->date_ = date();
	}

	bid::bid(const bid& b) {
		this->email_ = b.get_email();
		this->amount_ = b.get_amount();
		this->quantity_ = b.get_quantity();
		this->date_ = b.get_date();
	}

	bid::bid(string email, const float amount, const int quantity, date& date) {
		this->email_ = std::move(email);
		this->amount_ = amount;
		this->quantity_ = quantity;
		this->date_ = date;
	}

	string bid::get_email() const { return this->email_; }
	float bid::get_amount() const { return this->amount_; }
	int bid::get_quantity() const { return this->quantity_; }
	date bid::get_date() const { return this->date_; }

	void bid::set_email(const string& email) { this->email_ = email; }
	void bid::set_amount(const float& amount) { this->amount_ = amount; }
	void bid::set_quantity(const int& quantity) { this->quantity_ = quantity; }
	void bid::set_date(const date& date) { this->date_ = date; }

	bool bid::operator<(const bid& rhs) const {
		return this->get_amount() < rhs.get_amount();
	}

	bool bid::operator==(const bid& rhs) const {
		return this->get_amount() == rhs.get_amount();
	}

	std::istream& operator>>(std::istream& stream, bid& b) {
		int quantity;
		float amount;
		string email;
		date date;

		stream >> email >> amount >> quantity >> date;
		b.set_amount(amount);
		b.set_date(date);
		b.set_email(email);
		b.set_quantity(quantity);

		return stream;
	}
}
