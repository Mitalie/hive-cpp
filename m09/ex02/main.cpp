#include <deque>
#include <iostream>
#include <limits>
#include <sstream>
#include <vector>

#include <time.h>

#include "PmergeMe.hpp"

timespec gettime()
{
	timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts;
}

timespec operator-(const timespec &a, const timespec &b)
{
	timespec result;
	result.tv_sec = a.tv_sec - b.tv_sec;
	result.tv_nsec = a.tv_nsec - b.tv_nsec;
	if (result.tv_nsec < 0)
	{
		result.tv_sec -= 1;
		result.tv_nsec += 1000000000L;
	}
	return result;
}

template <typename C>
bool fillColl(C &coll, int argc, char *argv[])
{
	for (int i = 1; i < argc; ++i)
	{
		std::istringstream iss(argv[i]);
		long long num;
		iss >> num;
		if (!iss.eof())
			iss >> std::ws;
		if (!iss || !iss.eof() || num < 0 || num > std::numeric_limits<unsigned int>::max())
		{
			std::cerr << "Invalid input: " << argv[i] << " is not a valid unsigned integer.\n";
			return false;
		}
		coll.push_back(static_cast<unsigned int>(num));
	}
	return true;
}

template <typename C>
void printColl(const C &coll)
{
	for (typename C::const_iterator it = coll.begin(); it != coll.end(); ++it)
		std::cout << *it << ' ';
	std::cout << '\n';
}

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " num1 num2 num3 ...\n";
		return 1;
	}

	// Validate input and retain unsorted sequence for "Before" output.
	std::vector<unsigned int> tmpVec;
	if (!fillColl(tmpVec, argc, argv))
		return 1;
	std::cout << "Before : ";
	printColl(tmpVec);

	timespec vecStart = gettime();
	std::vector<unsigned int> vec;
	fillColl(vec, argc, argv);
	PmergeMe<unsigned int>::sort(vec);
	timespec vecEnd = gettime();

	timespec deqStart = gettime();
	std::deque<unsigned int> deq;
	fillColl(deq, argc, argv);
	PmergeMe<unsigned int>::sort(deq);
	timespec deqEnd = gettime();

	std::cout << "After  : ";
	// std::cout << "After (vector): ";
	printColl(vec);
	// std::cout << "After (deque) : ";
	// printColl(deq);

	timespec vecTime = vecEnd - vecStart;
	timespec deqTime = deqEnd - deqStart;
	double vecSeconds = vecTime.tv_sec + vecTime.tv_nsec / 1e9;
	double deqSeconds = deqTime.tv_sec + deqTime.tv_nsec / 1e9;
	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vecSeconds << " s\n";
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deqSeconds << " s\n";
}
