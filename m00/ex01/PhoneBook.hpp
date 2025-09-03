#pragma once

#include "Contact.hpp"

class PhoneBook
{
private:
	static const unsigned int capacity = 8;
	Contact contacts[capacity];
	unsigned int entries;
	unsigned int next_index;

public:
	PhoneBook();

	void add(const Contact &new_contact);
	bool list();
	bool show(unsigned int index);
};
