#include <climits>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

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

void testFormCons()
{
	std::cout << YELLOW "- accepts any valid grade as requirement for signing" RSTN;
	for (int i = 1; i <= 150; i++)
		Form f("Test Name", i, 3);
	std::cout << YELLOW "- accepts any valid grade as requirement for execution" RSTN;
	for (int i = 1; i <= 150; i++)
		Form f("Test Name", 3, i);
	std::cout << YELLOW "- rejects invalid grades as requirement for signing with appropriate exceptions" RSTN;
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", 0, 3);)
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", -1, 3);)
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", INT_MIN, 3);)
	PRINT_CODE_THROWING(
		Form::GradeTooLowException,
		Form f("Test Name", 151, 3);)
	PRINT_CODE_THROWING(
		Form::GradeTooLowException,
		Form f("Test Name", INT_MAX, 3);)
	std::cout << YELLOW "- rejects invalid grades as requirement for execution with appropriate exceptions" RSTN;
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", 3, 0);)
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", 3, -1);)
	PRINT_CODE_THROWING(
		Form::GradeTooHighException,
		Form f("Test Name", 3, INT_MIN);)
	PRINT_CODE_THROWING(
		Form::GradeTooLowException,
		Form f("Test Name", 3, 151);)
	PRINT_CODE_THROWING(
		Form::GradeTooLowException,
		Form f("Test Name", 3, INT_MAX);)
}

void testFormInfo()
{
	Form f1("Frm1", 2, 42);
	Form f2("Frm2", 149, 109);
	std::cout << YELLOW "- name getter" RSTN;
	PRINT_VALUE(f1.getName())
	PRINT_VALUE(f2.getName())
	std::cout << YELLOW "- grade for signing getter" RSTN;
	PRINT_VALUE(f1.getGradeRequiredToSign())
	PRINT_VALUE(f2.getGradeRequiredToSign())
	std::cout << YELLOW "- grade for execution getter" RSTN;
	PRINT_VALUE(f1.getGradeRequiredToExecute())
	PRINT_VALUE(f2.getGradeRequiredToExecute())
	std::cout << YELLOW "- signing status getter" RSTN;
	std::cout << std::boolalpha; // print bools as true/false instead of 1/0
	PRINT_VALUE(f1.getIsSigned())
	PRINT_VALUE(f2.getIsSigned())
	std::cout << YELLOW "- stream output operator" RSTN;
	PRINT_VALUE(f1)
	PRINT_VALUE(f2)
}

void testSigning()
{
	std::cout << YELLOW "- bureaucrat of insufficient level can't sign form" RSTN;
	Form f1("Frm1", 20, 50);
	Bureaucrat b1("Name One", 40);
	PRINT_VALUE(f1);
	PRINT_VALUE(b1);
	PRINT_CODE(b1.signForm(f1);)
	PRINT_VALUE(f1);
	std::cout << YELLOW "- bureaucrat of sufficient level can sign form" RSTN;
	Form f2("Frm2", 30, 50);
	Bureaucrat b2("Name Two", 10);
	PRINT_VALUE(f2);
	PRINT_VALUE(b2);
	PRINT_CODE(b2.signForm(f2);)
	PRINT_VALUE(f2);
	std::cout << YELLOW "- Form::beSigned checks signer grade" RSTN;
	Form f3("Frm3", 3, 99);
	Bureaucrat b3("Name Three", 4);
	PRINT_VALUE(f3);
	PRINT_VALUE(b3);
	PRINT_CODE_THROWING(
		Form::GradeTooLowException,
		f3.beSigned(b3);)
	PRINT_CODE(b3.promote();)
	PRINT_VALUE(b3);
	PRINT_CODE(f3.beSigned(b3);)
	PRINT_VALUE(f3);
}

int main()
{
	std::cout << BYELLOW "==== Test 1: Bureaucrat construction ====" RSTN;
	testBureaucratCons();
	std::cout << BYELLOW "==== Test 2: Bureaucrat information ====" RSTN;
	testBureaucratInfo();
	std::cout << BYELLOW "==== Test 3: Bureaucrat increment and decrement ====" RSTN;
	testBureaucratIncDec();
	std::cout << BYELLOW "==== Test 4: Form construction ====" RSTN;
	testFormCons();
	std::cout << BYELLOW "==== Test 5: Form information ====" RSTN;
	testFormInfo();
	std::cout << BYELLOW "==== Test 6: Signing forms ====" RSTN;
	testSigning();
}
