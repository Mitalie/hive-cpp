#include "ShrubberyCreationForm.hpp"

#include <string>

#include "AForm.hpp"

static std::string const formName = "Shrubbery Creation";

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
	: AForm(formName, target, gradeRequiredToSign, gradeRequiredToExecute)
{
}

void ShrubberyCreationForm::action() const
{
	// TODO
}
