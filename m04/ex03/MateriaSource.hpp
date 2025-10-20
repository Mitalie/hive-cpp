#pragma once

#include <string>

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	~MateriaSource();
	MateriaSource();
	MateriaSource(MateriaSource const &other);
	MateriaSource &operator=(MateriaSource const &other);

	void learnMateria(AMateria *m);
	AMateria *createMateria(std::string const &type);

private:
	static const int libSize = 4;
	AMateria *library[libSize];
};
