#include <string>
#include <iostream>

int main()
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
