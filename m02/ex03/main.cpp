#include <exception>
#include <iostream>

#include "bsp.hpp"
#include "Point.hpp"

static void print_bsp(Point const a, Point const b, Point const c, Point const point)
{
	const char *side = bsp(a, b, c, point) ? "inside" : "outside";
	std::cout << "Point " << point << " is " << side << " the triangle.\n";
}

void bspTest_main()
{
	Point a(5, 0);
	Point b(3, 2);
	Point c(1, -4);

	std::cout << "Triangle ABC consist of points A" << a << ", B" << b << " and C" << c << ".\n";

	std::cout << "\nTesting points that should be inside:\n";
	print_bsp(a, b, c, Point(2, -2));
	print_bsp(a, b, c, Point(3, 1));
	print_bsp(a, b, c, Point(3.48f, -1.48f));
	print_bsp(a, b, c, Point(2.34f, 0));

	std::cout << "\nTesting points that should be on the edge:\n";
	print_bsp(a, b, c, Point(3, 2));
	print_bsp(a, b, c, Point(2, -1));
	print_bsp(a, b, c, Point(2.5f, -2.5f));
	print_bsp(a, b, c, Point(2.5f, 0.5f));

	std::cout << "\nTesting points that should be outside:\n";
	print_bsp(a, b, c, Point(1, 0));
	print_bsp(a, b, c, Point(3, -3));
	print_bsp(a, b, c, Point(2.32f, 0));
	print_bsp(a, b, c, Point(5, 0.02f));
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
