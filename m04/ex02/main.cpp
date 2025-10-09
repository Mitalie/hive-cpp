#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testBasic()
{
	const AAnimal *j = new Dog();
	const AAnimal *i = new Cat();
	std::cout << "\x1b[33mType: >\x1b[0m" << j->getType() << "\x1b[33m<\x1b[0m\n";
	std::cout << "\x1b[33mType: >\x1b[0m" << i->getType() << "\x1b[33m<\x1b[0m\n";
	j->makeSound();
	i->makeSound();
	delete j;
	delete i;
}

void testWrong()
{
	const WrongAnimal *meta = new WrongAnimal();
	const WrongAnimal *i = new WrongCat();
	std::cout << "\x1b[33mType: >\x1b[0m" << i->getType() << "\x1b[33m<\x1b[0m\n";
	std::cout << "\x1b[33mType: >\x1b[0m" << meta->getType() << "\x1b[33m<\x1b[0m\n";
	i->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
}

void testCopy()
{
	std::cout << "\x1b[33mDog:\x1b[0m\n";
	{
		Dog d1;
		const Dog d2(d1);
		d1 = d2;
	}
	std::cout << "\x1b[33mCat:\x1b[0m\n";
	{
		Cat c1;
		const Cat c2(c1);
		c1 = c2;
	}
	std::cout << "\x1b[33mDone\x1b[0m\n";
}

void testLeaks()
{
	int const numAnimals = 10;
	const AAnimal *animals[numAnimals];
	std::cout << "\x1b[33mCreating Dogs:\x1b[0m\n";
	for (int i = 0; i < numAnimals / 2; i++)
		animals[i] = new Dog();
	std::cout << "\x1b[33mCreating Cats:\x1b[0m\n";
	for (int i = numAnimals / 2; i < numAnimals; i++)
		animals[i] = new Cat();
	std::cout << "\x1b[33mDeleting Animals:\x1b[0m\n";
	for (int i = 0; i < numAnimals; i++)
		delete animals[i];
	std::cout << "\x1b[33mDone\x1b[0m\n";
}

void testDeep()
{
	{
		std::cout << "\x1b[33mCreating two Cats, the second a copy of the first:\x1b[0m\n";
		Cat c1;
		Cat c2(c1);
		std::cout << "\x1b[33mGiving each a different idea...\x1b[0m\n";
		c1.setIdea(0, "Knock the vase off the shelf");
		c2.setIdea(0, "Knock the cup off the table");
		std::cout << "\x1b[33mCat 1 idea 0: >\x1b[0m" << c1.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mCat 2 idea 0: >\x1b[0m" << c2.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mAssigning the first to the second:\x1b[0m\n";
		c2 = c1;
		std::cout << "\x1b[33mGiving each another different idea...\x1b[0m\n";
		c1.setIdea(1, "Take a nap");
		c2.setIdea(1, "Climb the curtains");
		std::cout << "\x1b[33mCat 1 idea 0: >\x1b[0m" << c1.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mCat 1 idea 1: >\x1b[0m" << c1.getIdea(1) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mCat 2 idea 0: >\x1b[0m" << c2.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mCat 2 idea 1: >\x1b[0m" << c2.getIdea(1) << "\x1b[33m<\x1b[0m\n";
	}
	{
		std::cout << "\x1b[33mCreating two Dogs, the second a copy of the first:\x1b[0m\n";
		Dog d1;
		Dog d2(d1);
		std::cout << "\x1b[33mGiving each a different idea...\x1b[0m\n";
		d1.setIdea(0, "Chew on some shoes");
		d2.setIdea(0, "Chew on some cables");
		std::cout << "\x1b[33mDog 1 idea 0: >\x1b[0m" << d1.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mDog 2 idea 0: >\x1b[0m" << d2.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mAssigning the first to the second:\x1b[0m\n";
		d2 = d1;
		std::cout << "\x1b[33mGiving each another different idea...\x1b[0m\n";
		d1.setIdea(1, "Bark at a squirrel");
		d2.setIdea(1, "Make muddy pawprints");
		std::cout << "\x1b[33mDog 1 idea 0: >\x1b[0m" << d1.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mDog 1 idea 1: >\x1b[0m" << d1.getIdea(1) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mDog 2 idea 0: >\x1b[0m" << d2.getIdea(0) << "\x1b[33m<\x1b[0m\n";
		std::cout << "\x1b[33mDog 2 idea 1: >\x1b[0m" << d2.getIdea(1) << "\x1b[33m<\x1b[0m\n";
	}
}

int main()
{
	std::cout << "\x1b[93m==== Test 1: Basic requirements ====\x1b[0m\n";
	testBasic();
	std::cout << "\x1b[93m==== Test 2: Copying ====\x1b[0m\n";
	testCopy();
	std::cout << "\x1b[93m==== Test 3: Doing it wrong ====\x1b[0m\n";
	testWrong();
	std::cout << "\x1b[93m==== Test 4: Don't leak Brains (check with valgrind) ====\x1b[0m\n";
	testLeaks();
	std::cout << "\x1b[93m==== Test 5: Don't share Brains ====\x1b[0m\n";
	testDeep();
	std::cout << "\x1b[93m==== Done ====\x1b[0m\n";
}
