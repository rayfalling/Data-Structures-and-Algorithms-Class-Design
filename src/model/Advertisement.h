#pragma once
#include "Bid.h"
#include "Date.h"
#include <iostream>
#include <queue>
#include <string>
using string = std::string;
namespace model{
	class advertisement final {
		int number_;
		int quantity_;
		string title_;
		string seller_email_;
		string body_;

		date start_;
		date close_;
		std::priority_queue<bid> bids_;

	public:
		virtual ~advertisement() = default;
		advertisement();
		advertisement(const advertisement& a);
		advertisement(string title, string seller_email, string body, date start,
		              date close, int quantity);

		void set_start(const date& start);
		void set_close(const date& close);
		void set_title(string title);
		void set_body(string body);
		void set_number(int number);
		void set_email(string email);
		void set_quantity(int quantity);

		[[nodiscard]] date get_start() const;
		[[nodiscard]] date get_close() const;
		[[nodiscard]] string get_title() const;
		[[nodiscard]] string get_body() const;
		[[nodiscard]] string get_email() const;
		[[nodiscard]] int get_number() const;
		[[nodiscard]] int get_quantity() const;

		bool operator==(const advertisement&) const;

		std::priority_queue<bid>& get_bids();
		[[nodiscard]] virtual std::vector<bid> get_top_dutch_bids() const;
	};

	std::istream& operator>>(std::istream& stream, advertisement& a);

}
