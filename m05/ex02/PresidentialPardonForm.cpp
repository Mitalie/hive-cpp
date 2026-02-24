#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>

#include "AForm.hpp"

static std::string const formName = "Presidential Pardon";

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
	: AForm(formName, target, gradeRequiredToSign, gradeRequiredToExecute)
{
}

void PresidentialPardonForm::action() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox\n";
}
