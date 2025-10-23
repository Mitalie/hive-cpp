#include "Form.hpp"

#include <ostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

Form::GradeTooHighException::GradeTooHighException()
	: std::logic_error("Grade too high for Form")
{
}

Form::GradeTooLowException::GradeTooLowException()
	: std::logic_error("Grade too low for Form")
{
}

Form::~Form()
{
}

Form::Form(
	std::string const &name,
	int gradeRequiredToSign,
	int gradeRequiredToExecute)
	: name(name),
	  gradeRequiredToSign(gradeRequiredToSign),
	  gradeRequiredToExecute(gradeRequiredToExecute),
	  isSigned(false)
{
	if (gradeRequiredToSign < minGrade)
		throw GradeTooHighException();
	if (gradeRequiredToSign > maxGrade)
		throw GradeTooLowException();
	if (gradeRequiredToExecute < minGrade)
		throw GradeTooHighException();
	if (gradeRequiredToExecute > maxGrade)
		throw GradeTooLowException();
}

Form::Form(Form const &other)
	: name(other.name),
	  gradeRequiredToSign(other.gradeRequiredToSign),
	  gradeRequiredToExecute(other.gradeRequiredToExecute)
{
}

std::string const &Form::getName() const
{
	return name;
}

int Form::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int Form::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

void Form::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, Form const &f)
{
	os << f.getName()
	   << ", a form requiring a bureaucrat of grade "
	   << f.getGradeRequiredToSign()
	   << " to sign and of grade "
	   << f.getGradeRequiredToExecute()
	   << " to execute, "
	   << (f.getIsSigned() ? "signed" : "not signed")
	   << ".";
	return os;
}
