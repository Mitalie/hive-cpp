#include <climits>
#include <exception>
#include <iostream>
#include <vector>

#include "Span.hpp"

void spantest_minimal()
{
	std::cout << "Minimal test (6, 3, 17, 9, 11):\n";
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
}

#define PRINT_CODE(stmt)                           \
	std::cout << "    \x1b[33m" #stmt "\x1b[0m\n"; \
	stmt

#define EXPECT_EXCEPTION(stmt)                                                                 \
	try                                                                                        \
	{                                                                                          \
		PRINT_CODE(stmt)                                                                       \
		std::cout << "      \x1b[31m- did not throw\x1b[0m\n";                                 \
	}                                                                                          \
	catch (const std::exception &e)                                                            \
	{                                                                                          \
		std::cout << "      \x1b[32m- caught expected exception: \x1b[0m" << e.what() << '\n'; \
	}

void spantest_preconditions()
{
	std::cout << "Preconditions:\n";
	PRINT_CODE(Span sp = Span(2));
	std::cout << "  Testing shortestSpan and longestSpan with 0 numbers:\n";
	EXPECT_EXCEPTION(sp.shortestSpan();)
	EXPECT_EXCEPTION(sp.longestSpan();)
	std::cout << "  Testing shortestSpan and longestSpan with 1 number:\n";
	PRINT_CODE(sp.addNumber(1);)
	EXPECT_EXCEPTION(sp.shortestSpan();)
	EXPECT_EXCEPTION(sp.longestSpan();)
	std::cout << "  Testing addNumber with full span:\n";
	PRINT_CODE(sp.addNumber(2);)
	EXPECT_EXCEPTION(sp.addNumber(3);)
}

void spantest_extermeValues()
{
	std::cout << "Extreme values:\n";
	PRINT_CODE(Span sp = Span(5);)
	PRINT_CODE(sp.addNumber(INT_MIN);)
	PRINT_CODE(sp.addNumber(INT_MAX);)
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
	PRINT_CODE(sp.addNumber(0);)
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
	PRINT_CODE(sp.addNumber(INT_MIN + 3);)
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
	PRINT_CODE(sp.addNumber(INT_MAX - 2);)
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
}

void spantest_large()
{
	const unsigned int N = 1000000;
	const unsigned int specialIndex = 10000;

	std::cout << "Large tests with " << N << " numbers:\n";
	std::cout << "  Test 1 (v=i*3):\n";
	Span sp = Span(N);
	for (unsigned int i = 0; i < N; ++i)
		sp.addNumber(i * 3);
	std::cout << "    Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "    Longest span: " << sp.longestSpan() << '\n';

	std::cout << "  Test 2 (v=5, except +5 at i=" << specialIndex << "):\n";
	Span sp2 = Span(N);
	for (unsigned int i = 0; i < N; ++i)
		sp2.addNumber(5 + ((i == specialIndex) ? 5 : 0));
	std::cout << "    Shortest span: " << sp2.shortestSpan() << '\n';
	std::cout << "    Longest span: " << sp2.longestSpan() << '\n';

	std::cout << "  Test 3 (v=i*10, except +2 at i=" << specialIndex << "):\n";
	Span sp3 = Span(N);
	for (unsigned int i = 0; i < N; ++i)
		sp3.addNumber(i * 10 + ((i == specialIndex) ? 2 : 0));
	std::cout << "    Shortest span: " << sp3.shortestSpan() << '\n';
	std::cout << "    Longest span: " << sp3.longestSpan() << '\n';
}

void spantest_iterator()
{
	std::cout << "Iterator insertion test (i=0..100, v=i*i):\n";
	PRINT_CODE(std::vector<int> vec;)
	PRINT_CODE(for (int i = 0; i < 101; ++i) vec.push_back(i * i);)
	PRINT_CODE(Span sp(vec.size());)
	PRINT_CODE(sp.addNumbers(vec.begin(), vec.end());)
	std::cout << "  Shortest span: " << sp.shortestSpan() << '\n';
	std::cout << "  Longest span: " << sp.longestSpan() << '\n';
}

int main()
{
	spantest_minimal();
	spantest_preconditions();
	spantest_extermeValues();
	spantest_large();
	spantest_iterator();
	return 0;
}
