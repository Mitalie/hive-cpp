#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <iostream>
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
	std::string filename = getTarget() + "_shrubbery";
	std::ofstream file(filename.c_str());
	file << "directory1\n"
			"|-- directory11\n"
			"|   `-- file111\n"
			"|-- directory12\n"
			"|   |-- directory121\n"
			"|   |   `-- file1211\n"
			"|   `-- file122\n"
			"`-- is-this-not-what-you-meant-by-tree.txt\n";
	std::cout << "Tree installed in " << filename <<".\n";
}
