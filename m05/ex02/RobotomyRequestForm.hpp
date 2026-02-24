#pragma once

#include <string>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	~RobotomyRequestForm();
	RobotomyRequestForm(std::string const &target);

private:
	// default constructor forbidden, target required
	RobotomyRequestForm();
	// assignment forbidden, member values are const
	RobotomyRequestForm operator=(RobotomyRequestForm const &other);

	virtual void action() const;

	static int const gradeRequiredToSign = 72;
	static int const gradeRequiredToExecute = 45;
};
