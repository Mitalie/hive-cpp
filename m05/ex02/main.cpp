#include <climits>
#include <exception>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

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

// Mock derived class to test abstract class AForm
class TestAForm : public AForm
{
public:
	TestAForm(std::string const &name, int gradeRequiredToSign, int gradeRequiredToExecute)
		: AForm(name, "<no target>", gradeRequiredToSign, gradeRequiredToExecute)
	{
	}

private:
	void action() const
	{
		std::cout << "TestAForm action taken\n";
	}
};

void testFormCons()
{
	std::cout << YELLOW "- accepts any valid grade as requirement for signing" RSTN;
	for (int i = 1; i <= 150; i++)
		TestAForm f("Test Name", i, 3);
	std::cout << YELLOW "- accepts any valid grade as requirement for execution" RSTN;
	for (int i = 1; i <= 150; i++)
		TestAForm f("Test Name", 3, i);
	std::cout << YELLOW "- rejects invalid grades as requirement for signing with appropriate exceptions" RSTN;
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", 0, 3);)
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", -1, 3);)
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", INT_MIN, 3);)
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		TestAForm f("Test Name", 151, 3);)
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		TestAForm f("Test Name", INT_MAX, 3);)
	std::cout << YELLOW "- rejects invalid grades as requirement for execution with appropriate exceptions" RSTN;
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", 3, 0);)
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", 3, -1);)
	PRINT_CODE_THROWING(
		AForm::GradeTooHighException,
		TestAForm f("Test Name", 3, INT_MIN);)
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		TestAForm f("Test Name", 3, 151);)
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		TestAForm f("Test Name", 3, INT_MAX);)
}

void testFormInfo()
{
	TestAForm f1("Frm1", 2, 42);
	TestAForm f2("Frm2", 149, 109);
	std::cout << YELLOW "- name getter" RSTN;
	PRINT_VALUE(f1.getName())
	PRINT_VALUE(f2.getName())
	std::cout << YELLOW "- target getter" RSTN;
	PRINT_VALUE(f1.getTarget())
	PRINT_VALUE(f2.getTarget())
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
	TestAForm f1("Frm1", 20, 50);
	Bureaucrat b1("Name One", 40);
	PRINT_VALUE(f1);
	PRINT_VALUE(b1);
	PRINT_CODE(b1.signForm(f1);)
	PRINT_VALUE(f1);
	std::cout << YELLOW "- bureaucrat of sufficient level can sign form" RSTN;
	TestAForm f2("Frm2", 30, 50);
	Bureaucrat b2("Name Two", 10);
	PRINT_VALUE(f2);
	PRINT_VALUE(b2);
	PRINT_CODE(b2.signForm(f2);)
	PRINT_VALUE(f2);
	std::cout << YELLOW "- AForm::beSigned checks signer grade" RSTN;
	TestAForm f3("Frm3", 3, 99);
	Bureaucrat b3("Name Three", 4);
	PRINT_VALUE(f3);
	PRINT_VALUE(b3);
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		f3.beSigned(b3);)
	PRINT_CODE(b3.promote();)
	PRINT_VALUE(b3);
	PRINT_CODE(f3.beSigned(b3);)
	PRINT_VALUE(f3);
}

void testExecution()
{
	Bureaucrat low("Low Grade", 150);
	Bureaucrat high("High Grade", 1);
	TestAForm u("TestForm", 100, 50);
	TestAForm s("TestForm", 100, 50);
	high.signForm(s);
	std::cout << YELLOW "- bureaucrat fails to execute unsigned form" RSTN;
	PRINT_CODE(high.executeForm(u);)
	std::cout << YELLOW "- bureaucrat of insufficient level fails to execute form" RSTN;
	PRINT_CODE(low.executeForm(s);)
	std::cout << YELLOW "- bureaucrat of sufficient level successfully executes form" RSTN;
	PRINT_CODE(high.executeForm(s);)
	std::cout << YELLOW "- AForm::execute checks requirements" RSTN;
	PRINT_CODE_THROWING(
		AForm::NotSignedException,
		u.execute(high);)
	PRINT_CODE_THROWING(
		AForm::GradeTooLowException,
		s.execute(low);)
	PRINT_CODE(s.execute(high);)
}

void testConcreteInfo()
{
	std::cout << YELLOW "- ShrubberyCreationForm" RSTN;
	ShrubberyCreationForm s("Copilot");
	PRINT_VALUE(s.getName());
	PRINT_VALUE(s.getTarget());
	PRINT_VALUE(s.getGradeRequiredToSign());
	PRINT_VALUE(s.getGradeRequiredToExecute());
	PRINT_VALUE(s);
	std::cout << YELLOW "- RobotomyRequestForm" RSTN;
	RobotomyRequestForm r("Claude");
	PRINT_VALUE(r.getName());
	PRINT_VALUE(r.getTarget());
	PRINT_VALUE(r.getGradeRequiredToSign());
	PRINT_VALUE(r.getGradeRequiredToExecute());
	PRINT_VALUE(r);
	std::cout << YELLOW "- PresidentialPardonForm" RSTN;
	PresidentialPardonForm p("ChatGPT");
	PRINT_VALUE(p.getName());
	PRINT_VALUE(p.getTarget());
	PRINT_VALUE(p.getGradeRequiredToSign());
	PRINT_VALUE(p.getGradeRequiredToExecute());
	PRINT_VALUE(p);
}

void testConcreteExec()
{
	Bureaucrat low("Low Grade", 150);
	Bureaucrat high("High Grade", 1);
	{
		std::cout << YELLOW "- ShrubberyCreationForm checks requirements and can be executed" RSTN;
		ShrubberyCreationForm s("Copilot");
		PRINT_CODE_THROWING(
			AForm::NotSignedException,
			s.execute(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			s.beSigned(low);)
		PRINT_CODE(s.beSigned(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			s.execute(low);)
		PRINT_CODE(s.execute(high);)
	}
	{
		std::cout << YELLOW "- RobotomyRequestForm checks requirements and can be executed" RSTN;
		RobotomyRequestForm r("Claude");
		PRINT_CODE_THROWING(
			AForm::NotSignedException,
			r.execute(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			r.beSigned(low);)
		PRINT_CODE(r.beSigned(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			r.execute(low);)
		PRINT_CODE(r.execute(high);)
	}
	{
		std::cout << YELLOW "- PresidentialPardonForm checks requirements and can be executed" RSTN;
		PresidentialPardonForm p("ChatGPT");
		PRINT_CODE_THROWING(
			AForm::NotSignedException,
			p.execute(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			p.beSigned(low);)
		PRINT_CODE(p.beSigned(high);)
		PRINT_CODE_THROWING(
			AForm::GradeTooLowException,
			p.execute(low);)
		PRINT_CODE(p.execute(high);)
	}
}

int main()
{
	try
	{
		std::cout << BYELLOW "==== Test 1: Bureaucrat construction ====" RSTN;
		testBureaucratCons();
		std::cout << BYELLOW "==== Test 2: Bureaucrat information ====" RSTN;
		testBureaucratInfo();
		std::cout << BYELLOW "==== Test 3: Bureaucrat increment and decrement ====" RSTN;
		testBureaucratIncDec();
		std::cout << BYELLOW "==== Test 4: AForm construction ====" RSTN;
		testFormCons();
		std::cout << BYELLOW "==== Test 5: AForm information ====" RSTN;
		testFormInfo();
		std::cout << BYELLOW "==== Test 6: Signing forms ====" RSTN;
		testSigning();
		std::cout << BYELLOW "==== Test 7: Executing forms ====" RSTN;
		testExecution();
		std::cout << BYELLOW "==== Test 8: Concrete forms construction and information ====" RSTN;
		testConcreteInfo();
		std::cout << BYELLOW "==== Test 9: Concrete forms signing and execution ====" RSTN;
		testConcreteExec();
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
