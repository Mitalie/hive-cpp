#include <iostream>

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

void testOCF()
{
	std::cout << "\x1b[33mCure:\x1b[0m\n";
	{
		Cure cure;
		Cure cure2(cure);
		cure = cure2;
	}
	std::cout << "\x1b[33mIce:\x1b[0m\n";
	{
		Ice ice;
		Ice ice2(ice);
		ice = ice2;
	}
}

void testMatPolymorphic()
{
	std::cout << "\x1b[33mConstructing concrete materia:\x1b[0m\n";
	Cure cure;
	Ice ice;
	AMateria &mat1 = cure;
	AMateria &mat2 = ice;
	std::cout << "\x1b[33mUsing via AMateria references:\x1b[0m\n";
	// FIXME: implement once a concrete implementation of ICharacter is available
	std::cout << "\x1b[31m  Test not implemented yet\x1b[0m\n";
	std::cout << "\x1b[33mCloning via AMateria references:\x1b[0m\n";
	AMateria *clone1 = mat1.clone();
	AMateria *clone2 = mat2.clone();
	std::cout << "\x1b[33mDeleting the cloned AMateria pointers:\x1b[0m\n";
	delete clone1;
	delete clone2;
	std::cout << "\x1b[33mExiting scope\x1b[0m\n";
}

int main()
{
	std::cout << "\x1b[93m==== Test 1: Classes implement OCF ====\x1b[0m\n";
	testOCF();
	std::cout << "\x1b[93m==== Test 2: Cure and Ice implement AMateria ====\x1b[0m\n";
	testMatPolymorphic();
	std::cout << "\x1b[93m==== Done ====\x1b[0m\n";
}
