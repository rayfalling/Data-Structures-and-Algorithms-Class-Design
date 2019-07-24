#pragma once
#include "Bid.h"
#include "Date.h"
#include <iostream>
#include <queue>
#include <string>


using namespace std;

class advertisement;

istream& operator>>(istream& stream, advertisement& a);

class advertisement {

private:
	int number;
	int quantity;
	string title;
	string seller_email;
	string body;

	model::date start;
	model::date close;
	priority_queue<Bid> bids;

public:
	virtual ~advertisement() = default;
	advertisement();
	advertisement(const advertisement& a);
	advertisement(string title, string seller_email, string body, model::date start,
	              model::date close, int quantity);

	virtual void setStart(const model::date& start);
	virtual void setClose(const model::date& close);
	virtual void setTitle(string title);
	virtual void setBody(string body);
	virtual void setNumber(int number);
	virtual void setEmail(string email);
	virtual void setQuantity(int quantity);

	[[nodiscard]] virtual model::date getStart() const;
	[[nodiscard]] virtual model::date getClose() const;
	[[nodiscard]] virtual string getTitle() const;
	[[nodiscard]] virtual string getBody() const;
	[[nodiscard]] virtual string getEmail() const;
	[[nodiscard]] virtual int getNumber() const;
	[[nodiscard]] virtual int getQuantity() const;

	virtual bool operator==(const advertisement&) const;

	virtual priority_queue<Bid>& getBids();
	[[nodiscard]] virtual vector<Bid> getTopDutchBids() const;
};
