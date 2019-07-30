#pragma once
#include <string>
#include "Date.h"
using string = std::string;
namespace model{
	class client final {
		string firstname_;
		string lastname_;
		string email_;
		string password_;

	public:
		~client();
		client();
		client(client const& c);
		client(string& firstname, string& lastname, string& email, string& password);

		void set_firstname(const string&);
		void set_lastname(const string&);
		void set_email(const string&);
		void set_password(const string&);

		[[nodiscard]] string get_firstname() const;
		[[nodiscard]] string get_lastname() const;
		[[nodiscard]] string get_email() const;
		[[nodiscard]] string get_password() const;

		bool verify_password(string& password) const;

	};

	std::istream& operator>>(std::istream& stream, client& c);
}
