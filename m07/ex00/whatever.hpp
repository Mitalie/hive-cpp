#pragma once

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T const &a, T const &b)
{
	if (a < b)
		return a;
	return b; // b < a or equal
}

template <typename T>
T max(T const &a, T const &b)
{
	if (b < a)
		return a;
	return b; // a < b or equal
}
