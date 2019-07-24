#include "Date.h"
#include "Advertisement.h"
#include <utility>

advertisement::advertisement() {
	this->seller_email = "";
	this->title = "";
	this->body = "";
	this->quantity = 0;
	this->number = 0;
	this->start = model::date();
	this->close = model::date();
}

advertisement::advertisement(const advertisement& a) {
	this->seller_email = a.getEmail();
	this->title = a.getTitle();
	this->body = a.getBody();
	this->quantity = a.getQuantity();
	this->number = a.getNumber();
	this->start = a.getStart();
	this->close = a.getClose();
}

advertisement::advertisement(string title, string seller_email, string body,
                             model::date start, model::date close, int quantity) {
	this->seller_email = std::move(seller_email);
	this->title = std::move(title);
	this->body = std::move(body);
	this->quantity = quantity;
	this->number = number;
	this->start = std::move(start);
	this->close = std::move(close);
}

void advertisement::setStart(const model::date& start) { this->start = start; }
void advertisement::setClose(const model::date& close) { this->close = close; }
void advertisement::setTitle(string title) { this->title = std::move(title); }
void advertisement::setBody(string body) { this->body = std::move(body); }
void advertisement::setNumber(const int number) { this->number = number; }
void advertisement::setEmail(string email) { this->seller_email = std::move(email); }
void advertisement::setQuantity(const int quantity) { this->quantity = quantity; }

model::date advertisement::getStart() const { return this->start; }
model::date advertisement::getClose() const { return this->close; }
string advertisement::getTitle() const { return this->title; }
string advertisement::getBody() const { return this->body; }
string advertisement::getEmail() const { return this->seller_email; }
int advertisement::getNumber() const { return this->number; }
int advertisement::getQuantity() const { return this->quantity; }

bool advertisement::operator==(const advertisement& a) const {
	return this->number == a.getNumber();
}

priority_queue<Bid>& advertisement::getBids(void) { return this->bids; }

vector<Bid> advertisement::getTopDutchBids(void) const {

	vector<Bid> vector;
	priority_queue<Bid> tempBids = bids;
	int q = 0;
	while (!bids.empty() && q < quantity) {
		vector.push_back(tempBids.top());
		q += tempBids.top().getQuantity();
		tempBids.pop();
	}

	return vector;
}

istream& operator>>(istream& stream, advertisement& a) {
	string title, email, body;
	int quantity;
	model::date start, close;
	stream >> title >> email >> quantity >> start >> close >> body;

	a.setBody(body);
	a.setClose(close);
	a.setStart(start);
	a.setTitle(title);
	a.setQuantity(quantity);
	a.setEmail(email);

	return stream;
}
