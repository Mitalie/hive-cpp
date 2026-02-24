#include "AForm.hpp"

#include <ostream>
#include <string>
#include <stdexcept>

#include "Bureaucrat.hpp"

AForm::GradeTooHighException::GradeTooHighException()
	: std::logic_error("Grade too high for form")
{
}

AForm::GradeTooLowException::GradeTooLowException()
	: std::logic_error("Grade too low for form")
{
}

AForm::~AForm()
{
}

AForm::AForm(
	std::string const &name,
	std::string const &target,
	int gradeRequiredToSign,
	int gradeRequiredToExecute)
	: name(name),
	  target(target),
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

AForm::AForm(AForm const &other)
	: name(other.name),
	  gradeRequiredToSign(other.gradeRequiredToSign),
	  gradeRequiredToExecute(other.gradeRequiredToExecute)
{
}

std::string const &AForm::getName() const
{
	return name;
}

std::string const &AForm::getTarget() const
{
	return target;
}

int AForm::getGradeRequiredToSign() const
{
	return gradeRequiredToSign;
}

int AForm::getGradeRequiredToExecute() const
{
	return gradeRequiredToExecute;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

void AForm::beSigned(Bureaucrat const &signer)
{
	if (signer.getGrade() > gradeRequiredToSign)
		throw GradeTooLowException();
	isSigned = true;
}

std::ostream &operator<<(std::ostream &os, AForm const &f)
{
	os << f.getName()
	   << " for "
	   << f.getTarget()
	   << ", a form requiring a bureaucrat of grade "
	   << f.getGradeRequiredToSign()
	   << " to sign and of grade "
	   << f.getGradeRequiredToExecute()
	   << " to execute, "
	   << (f.getIsSigned() ? "signed" : "not signed")
	   << ".";
	return os;
}
