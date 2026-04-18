#include <cstddef>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

// In C++98 we can't use auto to deduce the iterator type. Specify it as a second template
// parameter for the actual implementation of testFind, and write a wrapper that specifies
// it based on the container type, overloaded for const and non-const containers.

template <typename Coll, typename It>
void testFind_impl(Coll &container, int value, const char *containerName)
{
	std::cout << "Searching for " << value << " in " << containerName << "...\n";
	std::cout << "    contents from begin():";
	for (It it = container.begin(); it != container.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	It found = easyfind(container, value);
	if (found == container.end())
		std::cout << "    easyfind() returned end() - value not found\n";
	else
	{
		std::cout << "    easyfind() returned a non-end() iterator\n";
		std::cout << "    contents from found position:";
		for (It it = found; it != container.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}

template <typename Coll>
void testFind(Coll &container, int value, const char *containerName)
{
	testFind_impl<Coll, typename Coll::iterator>(container, value, containerName);
}

template <typename Coll>
void testFind(const Coll &container, int value, const char *containerName)
{
	testFind_impl<const Coll, typename Coll::const_iterator>(container, value, containerName);
}

int main()
{
	const int nums[] = {1, 5, 8, 2, 6};
	const size_t numCount = sizeof(nums) / sizeof(nums[0]);
	std::vector<int> v(nums, nums + numCount);
	std::list<int> l(nums, nums + numCount);
	std::deque<int> d(nums, nums + numCount);
	const std::vector<int> &vc = v;
	const std::list<int> &lc = l;
	const std::deque<int> &dc = d;

	testFind(v, 3, "std::vector<int>");
	testFind(v, 8, "std::vector<int>");
	testFind(l, 3, "std::list<int>");
	testFind(l, 8, "std::list<int>");
	testFind(d, 3, "std::deque<int>");
	testFind(d, 8, "std::deque<int>");
	testFind(vc, 3, "const std::vector<int>");
	testFind(vc, 8, "const std::vector<int>");
	testFind(lc, 3, "const std::list<int>");
	testFind(lc, 8, "const std::list<int>");
	testFind(dc, 3, "const std::deque<int>");
	testFind(dc, 8, "const std::deque<int>");
}
