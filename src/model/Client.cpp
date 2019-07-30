#include "Client.h"
#include <string>
#include <iostream>

using string = std::string;

namespace model{
	client::~client() = default;

	client::client() {
		this->firstname_ = "";
		this->lastname_ = "";
		this->email_ = "";
		this->password_ = "";
	}

	client::client(client const& c) {
		this->firstname_ = c.get_firstname();
		this->lastname_ = c.get_lastname();
		this->email_ = c.get_email();
		this->password_ = c.get_password();
	}

	client::client(string& firstname, string& lastname, string& email, string& password) {
		this->firstname_ = firstname;
		this->lastname_ = lastname;
		this->email_ = email;
		this->password_ = password;
	}

	void client::set_firstname(const string& firstname) { this->firstname_ = firstname; }
	void client::set_lastname(const string& lastname) { this->lastname_ = lastname; }
	void client::set_email(const string& email) { this->email_ = email; }
	void client::set_password(const string& password) { this->password_ = password; }

	string client::get_firstname() const { return this->firstname_; }
	string client::get_lastname() const { return this->lastname_; }
	string client::get_email() const { return this->email_; }
	string client::get_password() const { return this->password_; }

	bool client::verify_password(string& password) const { return this->password_ == password; }

	std::istream& operator>>(std::istream& stream, client& c) {
		string firstname, lastname, email, password;
		stream >> firstname >> lastname >> email >> password;

		c.set_email(email);
		c.set_firstname(firstname);
		c.set_lastname(lastname);
		c.set_password(password);

		return stream;
	}

}
