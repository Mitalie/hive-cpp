#include <climits>
#include <iostream>

#include "Bureaucrat.hpp"

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BYELLOW "\x1b[93m"
#define RST "\x1b[0m"
#define RSTN "\x1b[0m\n"

#define PRINT_VALUE(expr) \
	std::cout << YELLOW "  - ostream << " #expr "; >" RST << expr << YELLOW "<" RSTN;

#define PRINT_CODE(code)                       \
	{                                          \
		std::cout << YELLOW "  - " #code RSTN; \
		{code};                                \
	}

#define PRINT_CODE_THROWING(extype, code)                        \
	try                                                          \
	{                                                            \
		std::cout << YELLOW "  - " #code RSTN;                   \
		{code};                                                  \
		std::cout << RED "    Did not throw" RSTN;               \
	}                                                            \
	catch (const extype &e)                                      \
	{                                                            \
		std::cout << GREEN "    Caught " #extype ", msg: >" RST  \
				  << e.what() << GREEN "<" RSTN;                 \
	}                                                            \
	catch (...)                                                  \
	{                                                            \
		std::cout << RED "    Caught something unexpected" RSTN; \
	}

void testBureaucratCons()
{
	std::cout << YELLOW "- accepts any valid grade" RSTN;
	for (int i = 1; i <= 150; i++)
		Bureaucrat b("Test Name", i);
	std::cout << YELLOW "- rejects invalid grades with appropriate exceptions" RSTN;
	PRINT_CODE_THROWING(
		Bureaucrat::GradeTooHighException,
		Bureaucrat b("Test Name", 0);)
	PRINT_CODE_THROWING(
		Bureaucrat::GradeTooHighException,
		Bureaucrat b("Test Name", -1);)
	PRINT_CODE_THROWING(
		Bureaucrat::GradeTooHighException,
		Bureaucrat b("Test Name", INT_MIN);)
	PRINT_CODE_THROWING(
		Bureaucrat::GradeTooLowException,
		Bureaucrat b("Test Name", 151);)
	PRINT_CODE_THROWING(
		Bureaucrat::GradeTooLowException,
		Bureaucrat b("Test Name", INT_MAX);)
}

void testBureaucratInfo()
{
	Bureaucrat b1("Name One", 2);
	Bureaucrat b2("Name Two", 149);
	std::cout << YELLOW "- name getter" RSTN;
	PRINT_VALUE(b1.getName())
	PRINT_VALUE(b2.getName())
	std::cout << YELLOW "- grade getter" RSTN;
	PRINT_VALUE(b1.getGrade())
	PRINT_VALUE(b2.getGrade())
	std::cout << YELLOW "- stream output operator" RSTN;
	PRINT_VALUE(b1)
	PRINT_VALUE(b2)
}

void testBureaucratIncDec()
{
	std::cout << YELLOW "- increment" RSTN;
	Bureaucrat b1("Name One", 3);
	PRINT_VALUE(b1)
	PRINT_CODE(b1.promote();)
	PRINT_VALUE(b1)
	PRINT_CODE(b1.promote();)
	PRINT_VALUE(b1)
	PRINT_CODE_THROWING(Bureaucrat::GradeTooHighException, b1.promote();)
	PRINT_VALUE(b1)
	std::cout << YELLOW "- decrement" RSTN;
	Bureaucrat b2("Name One", 148);
	PRINT_VALUE(b2)
	PRINT_CODE(b2.demote();)
	PRINT_VALUE(b2)
	PRINT_CODE(b2.demote();)
	PRINT_VALUE(b2)
	PRINT_CODE_THROWING(Bureaucrat::GradeTooLowException, b2.demote();)
	PRINT_VALUE(b2)
}

int main()
{
	std::cout << BYELLOW "==== Test 1: Bureaucrat construction ====" RSTN;
	testBureaucratCons();
	std::cout << BYELLOW "==== Test 2: Bureaucrat information ====" RSTN;
	testBureaucratInfo();
	std::cout << BYELLOW "==== Test 3: Bureaucrat increment and decrement ====" RSTN;
	testBureaucratIncDec();
}
