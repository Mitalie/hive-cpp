#include <iostream>
#include <list>
#include <stack>
#include <vector>

#include "MutantStack.hpp"

#define PRINT_CODE(stmt)                           \
	std::cout << "    \x1b[33m" #stmt "\x1b[0m\n"; \
	stmt

void mutantstack_test()
{
	std::cout << "MutantStack test:\n";

	MutantStack<int> mstack;

	PRINT_CODE(mstack.push(5);)
	PRINT_CODE(mstack.push(17);)

	std::cout << "  - top(): " << mstack.top() << '\n';

	PRINT_CODE(mstack.pop();)

	std::cout << "  - size(): " << mstack.size() << '\n';

	PRINT_CODE(mstack.push(3);)
	PRINT_CODE(mstack.push(5);)
	PRINT_CODE(mstack.push(737);)
	PRINT_CODE(mstack.push(0);)

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "  - list contents:\n";
	while (it != ite)
	{
		std::cout << "    " << *it << '\n';
		++it;
	}
	std::stack<int> s(mstack);
}

void list_test()
{
	std::cout << "List test:\n";

	std::list<int> mstack;

	PRINT_CODE(mstack.push_back(5);)
	PRINT_CODE(mstack.push_back(17);)

	std::cout << "  - back(): " << mstack.back() << '\n';

	PRINT_CODE(mstack.pop_back();)

	std::cout << "  - size(): " << mstack.size() << '\n';

	PRINT_CODE(mstack.push_back(3);)
	PRINT_CODE(mstack.push_back(5);)
	PRINT_CODE(mstack.push_back(737);)
	PRINT_CODE(mstack.push_back(0);)

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "  - list contents:\n";
	while (it != ite)
	{
		std::cout << "    " << *it << '\n';
		++it;
	}
	std::stack<int, std::list<int> > s(mstack);
}

void extra_test()
{
	std::cout << "Extra tests:\n";
	std::cout << "  - std::vector as the underlying container\n";
	MutantStack<int, std::vector<int> > mstack;
	PRINT_CODE(mstack.push(1);)
	PRINT_CODE(mstack.push(2);)
	PRINT_CODE(mstack.push(3);)
	PRINT_CODE(mstack.push(4);)
	std::cout << "  - top(): " << mstack.top() << '\n';
	std::cout << "  - size(): " << mstack.size() << '\n';
	PRINT_CODE(mstack.pop();)
	std::cout << "  - top(): " << mstack.top() << '\n';
	std::cout << "  - size(): " << mstack.size() << '\n';

	const MutantStack<int, std::vector<int> > &cmstack = mstack;
	MutantStack<int, std::vector<int> >::const_iterator it = cmstack.begin();
	MutantStack<int, std::vector<int> >::const_iterator ite = cmstack.end();
	std::cout << "  - list contents through const iterator:\n";
	while (it != ite)
	{
		std::cout << "    " << *it << '\n';
		++it;
	}
	std::cout << "  - modify contents through reverse iterator:\n";
	MutantStack<int, std::vector<int> >::reverse_iterator rit = mstack.rbegin();
	MutantStack<int, std::vector<int> >::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << "    " << *rit << " -> ";
		*rit += 10;
		std::cout << *rit << '\n';
		++rit;
	}
	std::cout << "  - list contents through reverse const iterator:\n";
	MutantStack<int, std::vector<int> >::const_reverse_iterator crit = cmstack.rbegin();
	MutantStack<int, std::vector<int> >::const_reverse_iterator crite = cmstack.rend();
	while (crit != crite)
	{
		std::cout << "    " << *crit << '\n';
		++crit;
	}
}

int main()
{
	mutantstack_test();
	std::cout << '\n';
	list_test();
	std::cout << '\n';
	extra_test();
}
