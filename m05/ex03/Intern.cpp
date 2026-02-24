#include "Intern.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::~Intern()
{
}

Intern::Intern()
{
}

Intern::Intern(Intern const &)
{
}

Intern &Intern::operator=(Intern const &)
{
	return *this;
}

static AForm *makePPF(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRRF(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

static AForm *makeSCF(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

typedef AForm *formFactory(std::string const &);
struct formFactoryEntry
{
	const char *name;
	formFactory &factory;
};

static formFactoryEntry const formFactories[] = {
	{"presidential pardon", makePPF},
	{"robotomy request", makeRRF},
	{"shrubbery creation", makeSCF},
};
static size_t const numFormFactories = sizeof formFactories / sizeof formFactories[0];

AForm *Intern::makeForm(std::string const &form, std::string const &target) const
{
	for (size_t i = 0; i < numFormFactories; ++i)
	{
		const formFactoryEntry &entry = formFactories[i];
		if (entry.name == form)
		{
			std::cout << "Intern creates " << form << "\n";
			return entry.factory(target);
		}
	}
	std::cout << "Intern does not know how to create " << form << "\n";
	return NULL;
}
