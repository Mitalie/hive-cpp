#include "RobotomyRequestForm.hpp"

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
	// TODO
}
