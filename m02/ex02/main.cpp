#include <exception>
#include <iostream>

#include "Fixed.hpp"

void test1()
{
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
}

void test2()
{
	Fixed const a(2.5f);
	Fixed b(a);

	std::cout << "a = " << a << " ; b = " << b << "\n\n";

	std::cout << "    b++ : " << b++ << "\n";
	std::cout << "      b : " << b << "\n";
	std::cout << "  a + b : " << a + b << "\n";
	std::cout << "  a - b : " << a - b << "\n";
	std::cout << "  a * b : " << a * b << "\n";
	std::cout << "  a / 2 : " << a / 2 << "\n";
	std::cout << "  b / 2 : " << a / 2 << "\n";
	std::cout << "++b / 2 : " << ++b / 2 << "\n";
	std::cout << "    --b : " << --b << "\n\n";

	std::cout << "a = " << a << " ; b = " << b << "\n\n";

	std::cout << " a < b : " << (a < b) << "\n";
	std::cout << " a > b : " << (a > b) << "\n";
	std::cout << "a <= b : " << (a <= b) << "\n";
	std::cout << "a >= b : " << (a >= b) << "\n";
	std::cout << "a == b : " << (a == b) << "\n";
	std::cout << "a != b : " << (a != b) << "\n\n";

	std::cout << " a < a : " << (a < a) << "\n";
	std::cout << " a > a : " << (a > a) << "\n";
	std::cout << "a <= a : " << (a <= a) << "\n";
	std::cout << "a >= a : " << (a >= a) << "\n";
	std::cout << "a == a : " << (a == a) << "\n";
	std::cout << "a != a : " << (a != a) << "\n\n";

	std::cout << " b < a : " << (b < a) << "\n";
	std::cout << " b > a : " << (b > a) << "\n";
	std::cout << "b <= a : " << (b <= a) << "\n";
	std::cout << "b >= a : " << (b >= a) << "\n";
	std::cout << "b == a : " << (b == a) << "\n";
	std::cout << "b != a : " << (b != a) << "\n\n";

	{
		Fixed const &res = (Fixed::min(a, b));
		std::cout << "Fixed::min(a, b) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::min(b, a));
		std::cout << "Fixed::min(b, a) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::max(a, b));
		std::cout << "Fixed::max(a, b) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::max(b, a));
		std::cout << "Fixed::max(b, a) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n\n";
	}

	std::cout << "    --b : " << --b << "\n\n";
	std::cout << "a = " << a << " ; b = " << b << "\n\n";

	{
		Fixed const &res = (Fixed::min(a, b));
		std::cout << "Fixed::min(a, b) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::min(b, a));
		std::cout << "Fixed::min(b, a) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::max(a, b));
		std::cout << "Fixed::max(a, b) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n";
	}
	{
		Fixed const &res = (Fixed::max(b, a));
		std::cout << "Fixed::max(b, a) : reference to "
				  << (&res == &a ? "a" : (&res == &b ? "b" : "<unknown>")) << "\n\n";
	}
}

void bspTest_main()
{
	std::cout << "==== Run tests from assignment ====\n\n";
	test1();
	std::cout << "\n==== Run additional tests ====\n\n";
	test2();
	std::cout << "\n==== Done ====" << std::endl;
}

int main()
{
	try
	{
		bspTest_main();
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
