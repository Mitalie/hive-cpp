#include "gen-ident.hpp"

#include <iostream>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate()
{
	static int next = 0;
	next = (next + 1) % 3; // totally random sequence of 1, 2, 0, 1, 2, 0...
	switch (next)
	{
	case 0:
		std::cout << "Generating A\n";
		return new A();
	case 1:
		std::cout << "Generating B\n";
		return new B();
	default:
		std::cout << "Generating C\n";
		return new C();
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Identified A*\n";
	else if (dynamic_cast<B *>(p))
		std::cout << "Identified B*\n";
	else if (dynamic_cast<C *>(p))
		std::cout << "Identified C*\n";
	else
		std::cout << "Unknown pointer type\n";
}

void identify(Base &p)
{
	// Wow, this nested try-catch is really ugly.
	// But we can't catch just std::bad_cast because we're forbidden from including <typeinfo>,
	// so we'd swallow potential exceptions from std::cout and mistake them as failed casts if we
	// tried to print and return inside the try blocks.
	try
	{
		(void)dynamic_cast<A &>(p);
	}
	catch (...)
	{
		try
		{
			(void)dynamic_cast<B &>(p);
		}
		catch (...)
		{
			try
			{
				(void)dynamic_cast<C &>(p);
			}
			catch (...)
			{
				std::cout << "Unknown reference type\n";
				return;
			}
			std::cout << "Identified C&\n";
			return;
		}
		std::cout << "Identified B&\n";
		return;
	}
	std::cout << "Identified A&\n";
}
