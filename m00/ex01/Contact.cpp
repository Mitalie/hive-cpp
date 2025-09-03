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

static void print_shorten(const std::string &field, unsigned int max_len)
{
	if (field.length() > max_len)
		std::cout << field.substr(0, max_len - 1) << '.';
	else
		std::cout << std::setw(max_len) << field;
}

void Contact::print_in_list(unsigned int index)
{
	const unsigned int field_len = 10;
	std::cout << std::setw(field_len) << index << '|';
	print_shorten(first_name, field_len);
	std::cout << '|';
	print_shorten(last_name, field_len);
	std::cout << '|';
	print_shorten(nickname, field_len);
	std::cout << '\n';
}

void Contact::print()
{
	std::cout << "First name     : " << first_name << '\n';
	std::cout << "Last name      : " << last_name << '\n';
	std::cout << "Nickname       : " << nickname << '\n';
	std::cout << "Phone number   : " << phone_number << '\n';
	std::cout << "Darkest secret : " << darkest_secret << '\n';
}
