#pragma once

#include <cstddef>

// Having a separate template parameter for the callback argument allows
// different but compatible types, e.g. T = int and U = int const

template <typename T, typename U>
void iter(T arr[], size_t const len, void callback(U &elem))
{
	for (size_t i = 0; i < len; i++)
		callback(arr[i]);
}
