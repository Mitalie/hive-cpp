#include "PhoneBook.hpp"

#include <iostream>

#include "Contact.hpp"

PhoneBook::PhoneBook()
	: contacts(),
	  entries(0),
	  next_index(0)
{
}

void PhoneBook::add(const Contact &new_contact)
{
	contacts[next_index] = new_contact;
	if (entries < capacity)
		entries++;
	next_index = (next_index + 1) % capacity;
}

bool PhoneBook::list()
{
	if (entries == 0)
		return false;
	std::cout << "     Index|First name| Last name|  Nickname\n"
				 "----------|----------|----------|----------\n";
	for (unsigned int i = 0; i < entries; i++)
		contacts[i].print_in_list(i);
	return true;
}

bool PhoneBook::show(unsigned int index)
{
	if (index >= entries)
		return false;
	contacts[index].print();
	return true;
}
