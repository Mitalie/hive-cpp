#include <cstddef>
#include <iostream>
#include <string>

#include "Harl.hpp"

enum HarlLevel
{
	HL_Debug,
	HL_Info,
	HL_Warning,
	HL_Error,
	HL_Unknown,
};

struct LevelEntry
{
	const char *str;
	const HarlLevel level;
};

HarlLevel strToLevel(std::string str)
{
	static const LevelEntry levels[] = {
		{"DEBUG", HL_Debug},
		{"INFO", HL_Info},
		{"WARNING", HL_Warning},
		{"ERROR", HL_Error},
	};
	const size_t entries = sizeof(levels) / sizeof(levels[0]);

	for (size_t i = 0; i < entries; ++i)
	{
		const LevelEntry &entry = levels[i];
		if (str == entry.str)
			return entry.level;
	}
	return HL_Unknown;
}

void harlFilter(Harl &harl, HarlLevel level)
{
	switch (level)
	{
	case HL_Debug:
		std::cout << "[ DEBUG ]" << std::endl;
		harl.complain("DEBUG");
		std::cout << std::endl;
	case HL_Info:
		std::cout << "[ INFO ]" << std::endl;
		harl.complain("INFO");
		std::cout << std::endl;
	case HL_Warning:
		std::cout << "[ WARNING ]" << std::endl;
		harl.complain("WARNING");
		std::cout << std::endl;
	case HL_Error:
		std::cout << "[ ERROR ]" << std::endl;
		harl.complain("ERROR");
		std::cout << std::endl;
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: harlFilter <level>\n";
		return 2;
	}
	Harl harl;
	harlFilter(harl, strToLevel(argv[1]));
	return 0;
}
