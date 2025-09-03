#include <iostream>
#include <sstream>
#include <string>

#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool input_nonempty(std::string prompt, std::string &input)
{
	while (std::cin.good())
	{
		std::cout << prompt;
		std::getline(std::cin, input);
		std::stringstream input_ss(input);
		input.clear();
		input_ss >> input;
		if (!input.empty())
			return true;
		std::cout << "Empty input not allowed\n";
	}
	return false;
}

static void handle_add(PhoneBook &phonebook)
{
	std::string first_name;
	if (!input_nonempty("Enter first name: ", first_name))
		return;
	std::string last_name;
	if (!input_nonempty("Enter last name: ", last_name))
		return;
	std::string nickname;
	if (!input_nonempty("Enter nickname: ", nickname))
		return;
	std::string phone_number;
	if (!input_nonempty("Enter phone number: ", phone_number))
		return;
	std::string darkest_secret;
	if (!input_nonempty("Enter darkest secret: ", darkest_secret))
		return;

	phonebook.add(Contact(first_name, last_name, nickname, phone_number, darkest_secret));
}

static void handle_search(PhoneBook &phonebook)
{
	if (!phonebook.list())
	{
		std::cout << "No entries\n";
		return;
	}
	std::cout << "Enter entry index: ";
	std::string input;
	std::getline(std::cin, input);
	std::stringstream input_ss(input);
	unsigned int index;
	if (!(input_ss >> index) || !phonebook.show(index))
		std::cout << "Invalid index\n";
}

int main()
{
	PhoneBook phonebook;

	while (std::cin.good())
	{
		std::cout << "Enter a command: ";
		std::string command;
		std::getline(std::cin, command);
		if (command == "ADD")
			handle_add(phonebook);
		else if (command == "SEARCH")
			handle_search(phonebook);
		else if (command == "EXIT")
			return 0;
		else
			std::cout << "Unrecognized command\n";
	}
}
