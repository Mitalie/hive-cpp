#include "Contact.hpp"

#include <iomanip>
#include <iostream>
#include <string>

Contact::Contact()
{
}

Contact::Contact(
	const std::string &first_name,
	const std::string &last_name,
	const std::string &nickname,
	const std::string &phone_number,
	const std::string &darkest_secret)
	: first_name(first_name),
	  last_name(last_name),
	  nickname(nickname),
	  phone_number(phone_number),
	  darkest_secret(darkest_secret)
{
}

static void print_shorten(const std::string &field, size_t max_len)
{
	if (field.length() > max_len)
		std::cout << field.substr(0, max_len - 1) << '.';
	else
		std::cout << std::setw(max_len) << field;
}

void Contact::print_short(unsigned int index)
{
	const size_t field_len = 10;
	std::cout << std::setw(field_len) << index << '|';
	print_shorten(first_name, field_len);
	print_shorten(last_name, field_len);
	print_shorten(nickname, field_len);
}

void Contact::print_full()
{
	std::cout << "First name     :" << first_name << std::endl;
	std::cout << "Last name      :" << last_name << std::endl;
	std::cout << "Nickname       :" << nickname << std::endl;
	std::cout << "Phone number   :" << phone_number << std::endl;
	std::cout << "Darkest secret :" << darkest_secret << std::endl;
}
