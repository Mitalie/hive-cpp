#pragma once

#include <algorithm>

// In C++98 we can't use auto or decltype to deduce the return type of easyfind. We could use a
// second template parameter for the iterator type, but that would be awkward for callers as it
// can't be deduced from the function arguments. Instead, we write two overloads of easyfind:
// one for non-const containers and one for const containers.

// get an iterator to the first occurrence of needle in haystack, or haystack.end() if not found
template <typename Coll>
typename Coll::iterator easyfind(Coll &haystack, int needle)
{
	return std::find(haystack.begin(), haystack.end(), needle);
}

// get an iterator to the first occurrence of needle in haystack, or haystack.end() if not found
template <typename Coll>
typename Coll::const_iterator easyfind(const Coll &haystack, int needle)
{
	return std::find(haystack.begin(), haystack.end(), needle);
}
