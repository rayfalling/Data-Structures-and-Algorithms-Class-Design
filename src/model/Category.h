#pragma once
#include <string>
#include <vector>

#include "Listing.h"

namespace model{
	class category final {
		int number_;
		int parent_;
		string name_;

		std::vector<category*> sub_categories_;
		std::vector<int> items_;

	public:
		~category() = default;
		category();
		category(int parent, string name);

		[[nodiscard]] int get_number() const;
		[[nodiscard]] int get_parent() const;
		[[nodiscard]] string get_name() const;

		void set_number(int);
		void set_parent(int);
		void set_name(string);

		void add_sub_category(category*);
		void add_item(int);

		void find_offerings(listing::iterator start,
		                    listing::iterator finish, listing& matches);
		void find_offerings_recursive(listing::iterator start,
		                              listing::iterator finish, listing& matches);

		std::vector<int>::iterator items_begin();
		std::vector<int>::iterator items_end();
		std::vector<category*>::iterator sub_categories_begin();
		std::vector<category*>::iterator sub_categories_end();

		bool operator==(const category& rhs) const;
	};

	std::istream& operator>>(std::istream& stream, category& c);

}
