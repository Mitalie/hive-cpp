#include <exception>
#include <iostream>

#include "Base.hpp"
#include "gen-ident.hpp"

class D : public Base
{
};

int main()
{
	try
	{
		for (int i = 0; i < 10; ++i)
		{
			Base *p = generate();
			identify(p);
			identify(*p);
			delete p;
			std::cout << '\n';
		}

		std::cout << "Testing with an unknown type:\n";
		Base *p = new D();
		identify(p);
		identify(*p);
		delete p;
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
