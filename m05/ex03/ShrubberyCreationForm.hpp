#pragma once

#include <string>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	~ShrubberyCreationForm();
	ShrubberyCreationForm(std::string const &target);

private:
	// default constructor forbidden, target required
	ShrubberyCreationForm();
	// assignment forbidden, member values are const
	ShrubberyCreationForm operator=(ShrubberyCreationForm const &other);

	virtual void action() const;

	static int const gradeRequiredToSign = 145;
	static int const gradeRequiredToExecute = 137;
};
