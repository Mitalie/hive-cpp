#include "Harl.hpp"

#include <cstddef>
#include <iostream>
#include <string>

typedef void (Harl::*member_fn_ptr)();

struct str_fn_entry
{
	const char *str;
	const member_fn_ptr fn;
};

void Harl::complain(std::string level)
{
	static const str_fn_entry levels[] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error},
	};
	static const size_t num_levels = sizeof(levels) / sizeof(levels[0]);

	for (size_t i = 0; i < num_levels; ++i)
	{
		const str_fn_entry &entry = levels[i];
		if (level == entry.str)
		{
			const member_fn_ptr complain_fn = entry.fn;
			(this->*complain_fn)();
			return;
		}
	}
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
