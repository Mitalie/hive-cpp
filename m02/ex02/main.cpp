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
}

int main()
{
	std::cout << "==== Run tests from assignment ====\n\n";
	test1();
	std::cout << "\n==== Run additional tests ====\n\n";
	test2();
	std::cout << "\n==== Done ====" << std::endl;
}
