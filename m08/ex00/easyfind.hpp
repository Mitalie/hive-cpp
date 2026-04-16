#pragma once

#include <algorithm>

// get an iterator to the first occurrence of needle in haystack, or haystack.end() if not found
template <typename T>
typename T::const_iterator easyfind(const T &haystack, int needle)
{
	return std::find(haystack.begin(), haystack.end(), needle);
}
