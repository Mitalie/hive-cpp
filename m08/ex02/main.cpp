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

int main()
{
	mutantstack_test();
	std::cout << '\n';
	list_test();
}
