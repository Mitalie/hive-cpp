#include <exception>
#include <iostream>
#include <string>

void brain_main()
{
	std::string stringVAR = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "Address            of stringVAR: " << &stringVAR << std::endl;
	std::cout << "Address     stored in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address referenced by stringREF: " << &stringREF << std::endl;

	std::cout << "Value            of stringVAR: " << stringVAR << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value referenced by stringREF: " << stringREF << std::endl;
}

int main()
{
	try
	{
		brain_main();
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
