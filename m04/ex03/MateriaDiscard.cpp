#include "MateriaDiscard.hpp"

#include "AMateria.hpp"

MateriaDiscard MateriaDiscard::instance;

void MateriaDiscard::discard(AMateria *m)
{
	instance.addToList(m);
}

void MateriaDiscard::clear()
{
	instance.deleteList();
}

MateriaDiscard::~MateriaDiscard()
{
	deleteList();
}

MateriaDiscard::MateriaDiscard()
	: list()
{
}

void MateriaDiscard::addToList(AMateria *m)
{
	ListNode *node = new ListNode;
	node->m = m;
	node->next = list;
	list = node;
}

void MateriaDiscard::deleteList()
{
	while (list)
	{
		ListNode *node = list;
		list = node->next;
		delete node->m;
		delete node;
	}
}
