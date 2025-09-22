#include <cctype>
#include <exception>
#include <iostream>
#include <string>

void megaphone_main(int argc, char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		for (std::string::iterator it = arg.begin(); it < arg.end(); ++it)
			*it = static_cast<char>(toupper(static_cast<unsigned char>(*it)));
		std::cout << arg;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	try
	{
		megaphone_main(argc, argv);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "Unknown exception" << std::endl;
		return 1;
	}
}
