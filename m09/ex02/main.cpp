#include <cstddef>
#include <iostream>
#include <sstream>
#include <vector>

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " num1 num2 num3 ...\n";
		return 1;
	}
	std::vector<int> vec(argc - 1);
	for (int i = 1; i < argc; ++i)
		std::istringstream(argv[i]) >> vec[i - 1];
	PmergeMe<int>::sort(vec);
	for (size_t i = 0; i < vec.size(); ++i)
		std::cout << vec[i] << ' ';
	std::cout << '\n';
}
