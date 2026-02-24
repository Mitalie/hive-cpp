#pragma once

#include <iosfwd>
#include <string>
#include <stdexcept>

class AForm;

class Bureaucrat
{
public:
	~Bureaucrat();
	Bureaucrat(std::string const &name, int grade);
	Bureaucrat(Bureaucrat const &other);

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

	std::string const &getName() const;
	int getGrade() const;
	void promote();
	void demote();
	void signForm(AForm &f) const;

private:
	// default constructor forbidden, name and grade required
	Bureaucrat();
	// assignment forbidden, name is const
	Bureaucrat &operator=(Bureaucrat const &other);

	std::string const name;
	int grade;

	static int const minGrade = 1;
	static int const maxGrade = 150;
};

std::ostream &operator<<(std::ostream &os, Bureaucrat const &b);
