#include <exception>
#include <cstddef>
#include <iostream>
#include <string>

#include "iter.hpp"

template <typename T>
static size_t arrsize(T const &arr)
{
	return sizeof arr / sizeof arr[0];
}

template <typename T>
static void dec2(T &num)
{
	num -= 2;
}

template <typename T>
static void printNums(T const &num)
{
	std::cout << "   |" << num << '\n';
}

static void printSyms(int const &num)
{
	std::cout << "   |";
	if (num < 0)
		for (int i = 0; i < -num; i++)
			std::cout << '-';
	else
		for (int i = 0; i < num; i++)
			std::cout << '+';
	std::cout << '\n';
}

static void printStrs(std::string const &s)
{
	std::cout << "   |" << s << '\n';
}

static void appendExclamation(std::string &s)
{
	s += '!';
}

void itertest_main()
{
	int iarr[5] = {3, 2, 1, 0, -1};
	std::cout << "print array of ints as symbols (callback with int const &)\n";
	iter(iarr, arrsize(iarr), printSyms);
	std::cout << "\ndecrement array of ints by 2 (callback with int &)\n";
	iter(iarr, arrsize(iarr), dec2<int>);
	std::cout << "\nprint array of ints as symbols (callback with int const &)\n";
	iter(iarr, arrsize(iarr), printSyms);
	std::cout << "\n====================\n";

	float farr[5] = {3.14f, 2.71f, 1.41f, 0.0f, -1.0f};
	std::cout << "\nprint array of floats (callback with float const &)\n";
	iter(farr, arrsize(farr), printNums<float>);
	std::cout << "\ndecrement array of floats by 2 (callback with float &)\n";
	iter(farr, arrsize(farr), dec2<float>);
	std::cout << "\nprint array of floats (callback with float const &)\n";
	iter(farr, arrsize(farr), printNums<float>);
	std::cout << "\n====================\n";

	std::string sarr[5] = {"apple", "banana", "cherry", "grape", "orange"};
	std::cout << "\nprint array of strings (callback with std::string const &)\n";
	iter(sarr, arrsize(sarr), printStrs);
	std::cout << "\nappend '!' to array of strings (callback with std::string &)\n";
	iter(sarr, arrsize(sarr), appendExclamation);
	std::cout << "\nprint array of strings (callback with std::string const &)\n";
	iter(sarr, arrsize(sarr), printStrs);
}

int main()
{
	try
	{
		itertest_main();
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
