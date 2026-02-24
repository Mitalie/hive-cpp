#pragma once

#include <iosfwd>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	virtual ~AForm() = 0;
	AForm(
		std::string const &name,
		std::string const &target,
		int gradeRequiredToSign,
		int gradeRequiredToExecute);
	AForm(AForm const &other);

	class GradeTooHighException : public std::logic_error
	{
	public:
		GradeTooHighException();
	};
	class GradeTooLowException : public std::logic_error
	{
	public:
		GradeTooLowException();
	};
	class NotSignedException : public std::logic_error
	{
	public:
		NotSignedException();
	};

	std::string const &getName() const;
	std::string const &getTarget() const;
	int getGradeRequiredToSign() const;
	int getGradeRequiredToExecute() const;
	bool getIsSigned() const;
	void beSigned(Bureaucrat const &signer);
	void execute(Bureaucrat const &executor) const;

private:
	// default constructor forbidden, name and grade requirements required
	AForm();
	// assignment forbidden, name and grade requirements are const
	AForm &operator=(AForm const &other);

	virtual void action() const = 0;

	std::string const name;
	std::string const target;
	int const gradeRequiredToSign;
	int const gradeRequiredToExecute;
	bool isSigned;

	static int const minGrade = 1;
	static int const maxGrade = 150;
};

std::ostream &operator<<(std::ostream &os, AForm const &f);
