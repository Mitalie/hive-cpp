#pragma once

#include <string>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	~PresidentialPardonForm();
	PresidentialPardonForm(std::string const &target);

private:
	// default constructor forbidden, target required
	PresidentialPardonForm();
	// assignment forbidden, member values are const
	PresidentialPardonForm operator=(PresidentialPardonForm const &other);

	virtual void action() const;

	static int const gradeRequiredToSign = 25;
	static int const gradeRequiredToExecute = 5;
};
