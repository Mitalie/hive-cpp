#include "MateriaSource.hpp"

#include <iostream>
#include <string>

#include "AMateria.hpp"

MateriaSource::~MateriaSource()
{
	std::cout << "Destructing MateriaSource\n";
	for (unsigned int i = 0; i < libSize; ++i)
		delete library[i];
}

MateriaSource::MateriaSource()
	: library()
{
	std::cout << "Default-constructing MateriaSource\n";
}

MateriaSource::MateriaSource(MateriaSource const &other)
	: library()
{
	std::cout << "Copy-constructing MateriaSource\n";
	for (unsigned int i = 0; i < libSize; ++i)
		if (other.library[i])
			library[i] = other.library[i]->clone();
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	std::cout << "Copy-assigning MateriaSource\n";
	for (unsigned int i = 0; i < libSize; ++i)
	{
		delete library[i];
		library[i] = 0;
	}
	for (unsigned int i = 0; i < libSize; ++i)
		if (other.library[i])
			library[i] = other.library[i]->clone();
	return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
	std::cout << "MateriaSource attempts to learn materia of type \"" << m->getType() << "\"...";
	for (unsigned int i = 0; i < libSize; ++i)
	{
		if (!library[i])
		{
			std::cout << " selected slot " << i << "\n";
			library[i] = m->clone();
			return;
		}
	}
	std::cout << " failed to learn, all slots in use\n";
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	std::cout << "MateriaSource attempts to create materia of type \"" << type << "\"...";
	for (unsigned int i = 0; i < libSize; ++i)
	{
		if (library[i] && library[i]->getType() == type)
		{
			std::cout << " found in slot " << i << "\n";
			return library[i]->clone();
		}
	}
	std::cout << " not found\n";
	return 0;
}
