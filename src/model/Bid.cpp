#include "Bid.h"

Bid::Bid() {
	this->email_ = "";
	this->amount_ = 0;
	this->quantity_ = 0;
	this->date_ = model::date();
}

Bid::Bid(const Bid& b) {
	this->email_ = b.getEmail();
	this->amount_ = b.getAmount();
	this->quantity_ = b.getQuantity();
	this->date_ = b.getDate();
}

Bid::Bid(string email, float amount, int quantity, model::date& date) {
	this->email_ = email;
	this->amount_ = amount;
	this->quantity_ = quantity;
	this->date_ = date;
}

string Bid::getEmail() const { return this->email_; }
float Bid::getAmount() const { return this->amount_; }
int Bid::getQuantity() const { return this->quantity_; }
model::date Bid::getDate() const { return this->date_; }

void Bid::setEmail(const string& email) { this->email_ = email; }
void Bid::setAmount(const float& amount) { this->amount_ = amount; }
void Bid::setQuantity(const int& quantity) { this->quantity_ = quantity; }
void Bid::setDate(const model::date& date) { this->date_ = date; }

bool Bid::operator<(const Bid& rhs) const {
	return this->getAmount() < rhs.getAmount();
}

bool Bid::operator==(const Bid& rhs) const {
	return this->getAmount() == rhs.getAmount();
}

istream& operator>>(istream& stream, Bid& b) {
	int quantity;
	float amount;
	string email;
	model::date date;

	stream >> email >> amount >> quantity >> date;
	b.setAmount(amount);
	b.setDate(date);
	b.setEmail(email);
	b.setQuantity(quantity);

	return stream;
}
