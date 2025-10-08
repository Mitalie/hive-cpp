#include <iostream>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void testBasic()
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	std::cout << "\x1b[33mType: >\x1b[0m" << j->getType() << "\x1b[33m<\x1b[0m\n";
	std::cout << "\x1b[33mType: >\x1b[0m" << i->getType() << "\x1b[33m<\x1b[0m\n";
	std::cout << "\x1b[33mType: >\x1b[0m" << meta->getType() << "\x1b[33m<\x1b[0m\n";
	j->makeSound();
	i->makeSound();
	meta->makeSound();
	delete meta;
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
	std::cout << "\x1b[33mAnimal:\x1b[0m\n";
	{
		Animal a1;
		const Animal a2(a1);
		a1 = a2;
	}
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

int main()
{
	std::cout << "\x1b[93m==== Test 1: Basic requirements ====\x1b[0m\n";
	testBasic();
	std::cout << "\x1b[93m==== Test 2: Copying ====\x1b[0m\n";
	testCopy();
	std::cout << "\x1b[93m==== Test 3: Doing it wrong ====\x1b[0m\n";
	testWrong();
	std::cout << "\x1b[93m==== Done ====\x1b[0m\n";
}
