#include <exception>
#include <iostream>
#include <string>

#include "Array.hpp"

template <typename T>
static void printArray(Array<T> const &arr, const char *name, const char *wrap)
{
	for (unsigned int i = 0; i < arr.size(); i++)
		std::cout << "      " << name << "[" << i << "]: " << wrap << arr[i] << wrap << '\n';
}

// Helper macros to print with correct name, and with quotes for strings
#define PRINT_ARRAY(arr) printArray(arr, #arr, "")
#define PRINT_ARRAY_STR(arr) printArray(arr, #arr, "\"")

// Show the code being executed
#define PRINT_CODE(code)            \
	std::cout << "  > " #code "\n"; \
	code;

int main()
{
	std::cout << "Empty arrays can be created and destroyed and have size 0:" << '\n';
	{
		PRINT_CODE(Array<int> emptyInts;)
		PRINT_CODE(Array<float> emptyFloats;)
		PRINT_CODE(Array<std::string> emptyStrings;)
		std::cout << "      emptyInts.size(): " << emptyInts.size() << '\n';
		std::cout << "      emptyFloats.size(): " << emptyFloats.size() << '\n';
		std::cout << "      emptyStrings.size(): " << emptyStrings.size() << '\n';
	}

	std::cout << "Arrays with initial size can be created:" << '\n';
	PRINT_CODE(Array<int> ints(2);)
	PRINT_CODE(Array<float> floats(3);)
	PRINT_CODE(Array<std::string> strings(4);)
	std::cout << "      ints.size(): " << ints.size() << '\n';
	std::cout << "      floats.size(): " << floats.size() << '\n';
	std::cout << "      strings.size(): " << strings.size() << '\n';

	std::cout << "Array elements can be read using operator[] const:" << '\n';
	PRINT_CODE(const Array<int> &constInts = ints;)
	PRINT_CODE(const Array<float> &constFloats = floats;)
	PRINT_CODE(const Array<std::string> &constStrings = strings;)
	PRINT_ARRAY(constInts);
	PRINT_ARRAY(constFloats);
	PRINT_ARRAY_STR(constStrings);

	std::cout << "Array elements can be written using operator[] (code not shown):" << '\n';
	for (unsigned int i = 0; i < ints.size(); i++)
		ints[i] = i + 2;
	for (unsigned int i = 0; i < floats.size(); i++)
		floats[i] = i * 1.23f;
	for (unsigned int i = 0; i < strings.size(); i++)
		for (unsigned int j = 0; j < 4 - i; j++)
			strings[i] += "a";
	PRINT_ARRAY(ints);
	PRINT_ARRAY(floats);
	PRINT_ARRAY_STR(strings);

	std::cout << "Arrays can be copied using the copy constructor:" << '\n';
	PRINT_CODE(Array<int> copyInts(ints);)
	PRINT_ARRAY(copyInts);

	std::cout << "Arrays can be copied using the copy assignment operator:" << '\n';
	PRINT_CODE(Array<int> assignedInts(3);)
	PRINT_ARRAY(assignedInts);
	PRINT_CODE(assignedInts = ints;)
	PRINT_ARRAY(assignedInts);

	std::cout << "Copied arrays are independent of the original:" << '\n';
	PRINT_CODE(copyInts[0] = 42;)
	PRINT_CODE(assignedInts[1] = 84;)
	PRINT_ARRAY(ints);
	PRINT_ARRAY(copyInts);
	PRINT_ARRAY(assignedInts);

	std::cout << "Out-of-range access throws std::exception:" << '\n';
	try
	{
		PRINT_CODE(ints[2] = 10;)
		std::cout << "    Wait, how did we get here?\n";
	}
	catch (std::exception const &e)
	{
		std::cout << "    Caught exception: " << e.what() << '\n';
	}
}
