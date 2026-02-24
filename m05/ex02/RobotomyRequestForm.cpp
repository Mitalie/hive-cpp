#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AForm.hpp"

static std::string const formName = "Robotomy Request";

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
	: AForm(formName, target, gradeRequiredToSign, gradeRequiredToExecute)
{
}

void RobotomyRequestForm::action() const
{
	std::cout << "*BUZZZZZ* *WHIRRRR* ";
	bool success = std::rand() % 2;
	if (success)
		std::cout << getTarget() << " successfully robotomized!\n";
	else
		std::cout << "Robotomy on " << getTarget() << " failed!\n";
}
