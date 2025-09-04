#include "zombieHorde.hpp"

#include <string>

#include "Zombie.hpp"

/*
	It is not possible to use constructor parameters with new[]. Therefore a
	default constructor must exist to use new[].
	
	The default constructor can't set the desired name, so we must set it on
	each instance afterwards. Because the name member is private, we can't
	assign it directly. Either a setter must be added, or we can replace the
	default-constructed Zombie instances in the array by assigning correctly
	named instances over them.

	Because the instances in the array should be identical, we can use a single
	temporary instance as the source of the assignment to avoid constructing
	and destructing temporary instances on each loop iteration.
*/
Zombie *zombieHorde(int N, std::string name)
{
	Zombie hordeZombie(name);
	Zombie *array = new Zombie[N];
	for (int i = 0; i < N; ++i)
		array[i] = hordeZombie;
	return array;
}
