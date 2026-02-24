#pragma once

#include <string>

class AForm;

class Intern
{
public:
	~Intern();
	Intern();
	Intern(Intern const &);
	Intern &operator=(Intern const &);

	AForm *makeForm(std::string const &form, std::string const &target) const;
};
