#include "Date.h"
#include "Advertisement.h"
#include <utility>

namespace model{
	advertisement::advertisement() {
		this->seller_email_ = "";
		this->title_ = "";
		this->body_ = "";
		this->quantity_ = 0;
		this->number_ = 0;
		this->start_ = date();
		this->close_ = date();
	}

	advertisement::advertisement(const advertisement& a) {
		this->seller_email_ = a.get_email();
		this->title_ = a.get_title();
		this->body_ = a.get_body();
		this->quantity_ = a.get_quantity();
		this->number_ = a.get_number();
		this->start_ = a.get_start();
		this->close_ = a.get_close();
	}

	advertisement::advertisement(string title, string seller_email, string body,
	                             date start, date close, int quantity) {
		this->seller_email_ = std::move(seller_email);
		this->title_ = std::move(title);
		this->body_ = std::move(body);
		this->quantity_ = quantity;
		this->number_ = number_;
		this->start_ = std::move(start);
		this->close_ = std::move(close);
	}

	void advertisement::set_start(const date& start) { this->start_ = start; }
	void advertisement::set_close(const date& close) { this->close_ = close; }
	void advertisement::set_title(string title) { this->title_ = std::move(title); }
	void advertisement::set_body(string body) { this->body_ = std::move(body); }
	void advertisement::set_number(const int number) { this->number_ = number; }
	void advertisement::set_email(string email) { this->seller_email_ = std::move(email); }
	void advertisement::set_quantity(const int quantity) { this->quantity_ = quantity; }

	date advertisement::get_start() const { return this->start_; }
	date advertisement::get_close() const { return this->close_; }
	string advertisement::get_title() const { return this->title_; }
	string advertisement::get_body() const { return this->body_; }
	string advertisement::get_email() const { return this->seller_email_; }
	int advertisement::get_number() const { return this->number_; }
	int advertisement::get_quantity() const { return this->quantity_; }

	bool advertisement::operator==(const advertisement& a) const {
		return this->number_ == a.get_number();
	}

	std::priority_queue<bid>& advertisement::get_bids() { return this->bids_; }

	std::vector<bid> advertisement::get_top_dutch_bids() const {

		std::vector<bid> vector;
		auto temp_bids = bids_;
		auto q = 0;
		while (!bids_.empty() && q < quantity_) {
			vector.push_back(temp_bids.top());
			q += temp_bids.top().get_quantity();
			temp_bids.pop();
		}

		return vector;
	}

	std::istream& operator>>(std::istream& stream, advertisement& a) {
		string title, email, body;
		int quantity;
		date start, close;
		stream >> title >> email >> quantity >> start >> close >> body;

		a.set_body(body);
		a.set_close(close);
		a.set_start(start);
		a.set_title(title);
		a.set_quantity(quantity);
		a.set_email(email);

		return stream;
	}
}
