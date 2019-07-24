#pragma once
#include "Date.h"
#include <string>

using namespace std;

class Bid;

istream& operator>>(istream& stream, Bid& b);

class Bid {
	string email_;
	float amount_;
	int quantity_;
	model::date date_;

public:
	Bid(void);
	Bid(const Bid& b);
	Bid(string email, float amount, int quantity,  model::date& date);

	[[nodiscard]] virtual string getEmail() const;
	[[nodiscard]] virtual float getAmount() const;
	[[nodiscard]] virtual int getQuantity() const;
	[[nodiscard]] virtual model::date getDate() const;

	virtual void setEmail(const string&);
	virtual void setAmount(const float&);
	virtual void setQuantity(const int&);
	virtual void setDate(const model::date&);

	virtual bool operator<(const Bid& rhs) const;
	virtual bool operator==(const Bid& rhs) const;
};
