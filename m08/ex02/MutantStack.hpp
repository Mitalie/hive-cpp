#pragma once

#include <stack>

// Since we don't add data members or enforce any additional invariants, this functionality would be
// better implemented as free functions that take std::stack as an argument. However, the assignment
// specifically requests a class with std::stack's interface plus additional functionality.
// Additionally, `std::stack<int> s(mstack);` should work, so MutantStack<int> must be implicitly
// convertible to either std::stack<int> for copy construction, or to std::deque<int> (the default
// container type for std::stack) for copy construction of the underlying container.

// Public inheritance from std::stack is simple to implement, with the std::stack interface and
// copy-construction working with no code, but user must be careful with polymorphism. Slicing
// should not cause problems since we don't add any data members or invariants, but deleting through
// a pointer to std::stack causes undefined behavior since the destructor is not virtual. Private
// inheritance or composition would prevent dangerous polymorphic usage, but would require a lot of
// boilerplate to match the std::stack interface, especially without C++11's using-declarations.

// Extension of std::stack with iterators
// Must not be deleted via a pointer to std::stack, because std:stack's destructor is not virtual.
template <typename T, typename C = typename std::stack<T>::container_type>
class MutantStack : public std::stack<T, C>
{
public:
	typedef typename C::iterator iterator;

	iterator begin();
	iterator end();
};

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin()
{
	return this->c.begin();
}

template <typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end()
{
	return this->c.end();
}
