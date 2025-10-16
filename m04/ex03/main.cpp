#include <iostream>

#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaDiscard.hpp"

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
	std::cout << "\x1b[33mCharacter:\x1b[0m\n";
	{
		Character c;
		Character c2("Test");
		Character c3(c2);
		c2 = c;
		c = c3;
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
	{
		Character c("Tractice Parget");
		mat1.use(c);
		mat2.use(c);
	}
	std::cout << "\x1b[33mCloning via AMateria references:\x1b[0m\n";
	AMateria *clone1 = mat1.clone();
	AMateria *clone2 = mat2.clone();
	std::cout << "\x1b[33mDeleting the cloned AMateria pointers:\x1b[0m\n";
	delete clone1;
	delete clone2;
	std::cout << "\x1b[33mExiting scope\x1b[0m\n";
}

void testCharMatUse()
{
	std::cout << "\x1b[33mCreating characters\x1b[0m\n";
	ICharacter *c1 = new Character("Cest Tharacter");
	ICharacter *c2 = new Character("Tractice Parget");
	std::cout << "\x1b[33mCreating materia\x1b[0m\n";
	AMateria *mat[] = {new Ice, new Cure, new Cure, new Ice};
	std::cout << "\x1b[33mEquipping materia\x1b[0m\n";
	c1->equip(mat[0]);
	c1->equip(mat[1]);
	c1->equip(mat[2]);
	c1->equip(mat[3]);
	std::cout << "\x1b[33mUsing materia\x1b[0m\n";
	c1->use(0, *c2);
	c1->use(1, *c2);
	c1->use(2, *c2);
	c1->use(3, *c2);
	std::cout << "\x1b[33mDeleting characters\x1b[0m\n";
	delete c1;
	delete c2;
}

void testCharMatDiscard()
{
	std::cout << "\x1b[33mCreating character\x1b[0m\n";
	ICharacter *c1 = new Character("Cest Tharacter");
	std::cout << "\x1b[33mCreating materia\x1b[0m\n";
	AMateria *mat[] = {new Ice, new Cure, new Cure, new Ice, new Ice, new Cure};
	std::cout << "\x1b[33mEquipping materia\x1b[0m\n";
	c1->equip(mat[0]);
	c1->equip(mat[1]);
	c1->equip(mat[2]);
	c1->equip(mat[3]);
	c1->equip(mat[4]);
	c1->equip(mat[5]);
	std::cout << "\x1b[33mUnequipping materia\x1b[0m\n";
	c1->unequip(0);
	c1->unequip(1);
	c1->unequip(2);
	std::cout << "\x1b[33mDeleting character\x1b[0m\n";
	delete c1;
	std::cout << "\x1b[33mClearing floor of discarded materia\x1b[0m\n";
	MateriaDiscard::clear();
}

void testCharDeep()
{
	std::cout << "\x1b[33mCreating character with some materia\x1b[0m\n";
	Character c1("Cest Tharacter");
	c1.equip(new Ice);
	c1.equip(new Cure);
	{
		std::cout << "\x1b[33mCreating a copy and replacing a materia\x1b[0m\n";
		Character c2(c1);
		c2.unequip(1);
		c2.equip(new Ice);
		std::cout << "\x1b[33mCopy goes out of scope\x1b[0m\n";
	}
	std::cout << "\x1b[33mClearing floor of discarded materia\x1b[0m\n";
	MateriaDiscard::clear();
	std::cout << "\x1b[33mFirst character still has original materia\x1b[0m\n";
	Character t("Tractice Parget");
	c1.use(0, t);
	c1.use(1, t);
	{
		std::cout << "\x1b[33mCopy-assigning and replacing a materia\x1b[0m\n";
		Character c2;
		c2 = c1;
		c2.unequip(1);
		c2.equip(new Ice);
		std::cout << "\x1b[33mCopy goes out of scope\x1b[0m\n";
	}
	std::cout << "\x1b[33mClearing floor of discarded materia\x1b[0m\n";
	MateriaDiscard::clear();
	std::cout << "\x1b[33mFirst character still has original materia\x1b[0m\n";
	c1.use(0, t);
	c1.use(1, t);
	std::cout << "\x1b[33mExiting scope\x1b[0m\n";
}

int main()
{
	std::cout << "\x1b[93m==== Test 1: Classes implement OCF ====\x1b[0m\n";
	testOCF();
	std::cout << "\x1b[93m==== Test 2: Cure and Ice implement AMateria ====\x1b[0m\n";
	testMatPolymorphic();
	std::cout << "\x1b[93m==== Test 3: Character can equip and use materia ====\x1b[0m\n";
	testCharMatUse();
	std::cout << "\x1b[93m==== Test 4: Character can handle full inventory and unequip materia ====\x1b[0m\n";
	testCharMatDiscard();
	std::cout << "\x1b[93m==== Test 5: Character copies are deep copies ====\x1b[0m\n";
	testCharDeep();
	std::cout << "\x1b[93m==== Done ====\x1b[0m\n";
}
