#include "PresidentialPardonForm.hpp"

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
	// TODO
}
