#include "Category.h"

Category::Category(void) {
	this->number = 0;
	this->parent = 0;
	this->name = "";
	this->sub_categories = vector<Category *>();
	this->items = vector<int>();
}
Category::Category(int parent, string name) {
	this->number = 0;
	this->parent = parent;
	this->name = name;

	this->sub_categories = vector<Category *>();
	this->items = vector<int>();
}

int	Category::getNumber(void) const { return this->number; }
int	Category::getParent(void) const { return this->parent; }
string Category::getName(void) const { return this->name; }

void Category::setNumber(int number) { this->number = number; }
void Category::setParent(int parent) { this->parent = parent; }
void Category::setName(string name) { this->name = name; }

void Category::addSubCategory(Category *category) {
	this->sub_categories.push_back(category);
}
void Category::addItem(int item) { this->items.push_back(item); }

void Category::findOfferings(listing::iterator start, listing::iterator finish,
							 listing &matches) {
	listing::iterator	 it = start;
	vector<int>::iterator pit = this->items.begin();
	int					  len = 0;

	while (it != finish) {
		vector<int>::iterator search;
		if (find(this->itemsBegin(), this->itemsEnd(), (*it)->getNumber()) !=
			this->itemsEnd()) {
			matches.add(*it);
		}

		it++;
	}
}

void Category::findOfferingsRecursive(listing::iterator start,
									  listing::iterator finish,
									  listing &			matches) {
	findOfferings(start, finish, matches);
	auto it = this->subCategoriesBegin();
	while (it != this->subCategoriesEnd()) {
		(*it)->findOfferingsRecursive(start, finish, matches);
		it++;
	}
	// for_each(this->subCategoriesBegin(), this->subCategoriesEnd(),
	// 		 [&](vector<Category *>::iterator it) {
	// 			 (*it)->findOfferingsRecursive(start, finish, matches);
	// 		 });
}

vector<int>::iterator Category::itemsBegin() { return this->items.begin(); }
vector<int>::iterator Category::itemsEnd() { return this->items.end(); }
vector<Category *>::iterator Category::subCategoriesBegin() {
	return this->sub_categories.begin();
}
vector<Category *>::iterator Category::subCategoriesEnd() {
	return this->sub_categories.end();
}

bool Category::operator==(const Category &rhs) {
	return this->number == rhs.getNumber();
}

istream &operator>>(istream &stream, Category &c) {
	int	parent;
	string name;

	stream >> parent >> name;
	c.setParent(parent);
	c.setName(name);

	return stream;
}