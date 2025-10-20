#pragma once

class AMateria;

/*
	A class to handle Materia left behind by Character so that it can be deleted later.

	This is necessary because of "conflicting" requirements in the assignment:
	- We can't specify that caller retains ownership of all Materia passed to `ICharacter::equip`,
	  because Character is explicitly required to delete any Materia it holds upon destruction.
	- We can't specify that Character takes ownership of all Materia passed to `ICharacter::equip`
	  and then delete any that are not retained in the inventory, because `ICharacter::unequip` is
	  explicitly forbidden from deleting Materia.
	- We can't specify that the caller regains ownership of unequipped Materia, because
	  `ICharacter::unequip` neither returns a pointer to the unequipped Materia nor allows it to be
	  queried before calling.

	This means that Character must keep track of any unequipped Materia to allow them to be deleted
	later. This could be done within Character class, and separately for each instance, but a
	distinct class and a shared singleton are equally valid and provide a degree of separation.

	This same mechanism can also be used when `ICharacter::equip` is called with a full inventory,
	although assignment-as-written does not forbid immediate deletion there.
*/
class MateriaDiscard
{
public:
	/*
		Store a Materia instance in the list of discarded Materia, to be deleted later.
		Caller must not delete the instance and should not keep a pointer to it.
	*/
	static void discard(AMateria *m);
	/*
		Delete all Materia instances in the list of discarded Materia.
		This is also done automatically at the end of the program.
	*/
	static void clear();

private:
	// Destructor deletes the list if MateriaDiscard::clear is not called manually
	~MateriaDiscard();
	// Constructor is private to prevent creating additional instances
	MateriaDiscard();
	// Copying is not allowed
	MateriaDiscard(MateriaDiscard const &other);
	// Assignment is not allowed
	MateriaDiscard &operator=(MateriaDiscard const &other);

	void addToList(AMateria *m);
	void deleteList();

	/*
		A singleton instance to be used by all static member functions.
		Declared as a static member variable to access private constructor.
	*/
	static MateriaDiscard instance;

	struct ListNode
	{
		AMateria *m;
		ListNode *next;
	};
	ListNode *list;
};
