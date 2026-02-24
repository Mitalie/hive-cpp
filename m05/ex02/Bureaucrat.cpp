#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

#include "AForm.hpp"

Bureaucrat::GradeTooHighException::GradeTooHighException()
	: std::logic_error("Grade too high for Bureaucrat")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
	: std::logic_error("Grade too high for Bureaucrat")
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
	: name(name), grade(grade)
{
	if (grade < minGrade)
		throw GradeTooHighException();
	if (grade > maxGrade)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
	: name(other.name),
	  grade(other.grade)
{
}

std::string const &Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

void Bureaucrat::promote()
{
	if (grade <= minGrade)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::demote()
{
	if (grade >= maxGrade)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &f) const
{
	try
	{
		f.beSigned(*this);
		std::cout << name << " signed form " << f.getName() << "\n";
	}
	catch (AForm::GradeTooLowException const &e)
	{
		std::cout << name << " couldn't sign form " << f.getName()
				  << " because: " << e.what() << "\n";
	}
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
