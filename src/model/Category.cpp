#include "Category.h"
#include <utility>
#include <algorithm>

namespace model{
	category::category() {
		this->number_ = 0;
		this->parent_ = 0;
		this->name_ = "";
		this->sub_categories_ = std::vector<category*>();
		this->items_ = std::vector<int>();
	}

	category::category(const int parent, string name) {
		this->number_ = 0;
		this->parent_ = parent;
		this->name_ = std::move(name);
		this->sub_categories_ = std::vector<category*>();
		this->items_ = std::vector<int>();
	}

	int category::get_number() const { return this->number_; }
	int category::get_parent() const { return this->parent_; }
	string category::get_name() const { return this->name_; }

	void category::set_number(const int number) { this->number_ = number; }
	void category::set_parent(const int parent) { this->parent_ = parent; }
	void category::set_name(string name) { this->name_ = std::move(name); }

	void category::add_sub_category(category* category) {
		this->sub_categories_.push_back(category);
	}

	void category::add_item(const int item) { this->items_.push_back(item); }

	void category::find_offerings(listing::iterator start, listing::iterator finish, listing& matches) {
		auto it = start;
		auto pit = this->items_.begin();

		while (it != finish) {
			std::vector<int>::iterator search;
			if (std::find(this->items_begin(), this->items_end(), (*it)->get_number()) !=
				this->items_end()) {
				matches.add(*it);
			}
			++it;
		}
	}

	void category::find_offerings_recursive(listing::iterator start, listing::iterator finish, listing& matches) {
		find_offerings(start, finish, matches);
		auto it = this->sub_categories_begin();
		while (it != this->sub_categories_end()) {
			(*it)->find_offerings_recursive(start, finish, matches);
			++it;
		}
	}

	std::vector<int>::iterator category::items_begin() { return this->items_.begin(); }
	std::vector<int>::iterator category::items_end() { return this->items_.end(); }

	std::vector<category*>::iterator category::sub_categories_begin() {
		return this->sub_categories_.begin();
	}

	std::vector<category*>::iterator category::sub_categories_end() {
		return this->sub_categories_.end();
	}

	bool category::operator==(const category& rhs) const {
		return this->number_ == rhs.get_number();
	}

	std::istream& operator>>(std::istream& stream, category& c) {
		int parent;
		string name;

		stream >> parent >> name;
		c.set_parent(parent);
		c.set_name(name);

		return stream;
	}
}
