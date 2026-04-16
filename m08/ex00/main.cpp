#include <cstddef>
#include <deque>
#include <iostream>
#include <list>
#include <vector>

#include "easyfind.hpp"

template <typename T>
void testFind(const T &container, int value, const char *containerName)
{
	std::cout << "Searching for " << value << " in " << containerName << "...\n";
	std::cout << "    contents from begin():";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	typename T::const_iterator found = easyfind(container, value);
	if (found == container.end())
		std::cout << "    easyfind() returned end() - value not found\n";
	else
	{
		std::cout << "    easyfind() returned a non-end() iterator\n";
		std::cout << "    contents from found position:";
		for (typename T::const_iterator it = found; it != container.end(); ++it)
			std::cout << ' ' << *it;
		std::cout << '\n';
	}
}

int main()
{
	const int nums[] = {1, 5, 8, 2, 6};
	const size_t numCount = sizeof(nums) / sizeof(nums[0]);
	std::vector<int> v(nums, nums + numCount);
	std::list<int> l(nums, nums + numCount);
	std::deque<int> d(nums, nums + numCount);

	testFind(v, 3, "Vector");
	testFind(v, 8, "Vector");
	testFind(l, 3, "List");
	testFind(l, 8, "List");
	testFind(d, 3, "Deque");
	testFind(d, 8, "Deque");
}
