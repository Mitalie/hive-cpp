#pragma once

#include <stdexcept>

template <typename T>
class Array
{
public:
	~Array();
	Array();
	Array(unsigned int n);
	Array(Array const &);
	Array &operator=(Array const &);

	T &operator[](unsigned int i);
	T const &operator[](unsigned int i) const;
	unsigned int size() const;

private:
	T *arr;
	unsigned int len;
};

////// Implementation below

template <typename T>
Array<T>::~Array()
{
	delete[] arr;
}

template <typename T>
Array<T>::Array()
	: arr(0), len(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: arr(new T[n]()), len(n)
{
}

template <typename T>
Array<T>::Array(Array const &other)
	: arr(new T[other.len]), len(other.len)
{
	for (unsigned int i = 0; i < len; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	delete[] arr;
	arr = new T[other.len];
	len = other.len;
	for (unsigned int i = 0; i < len; i++)
		arr[i] = other.arr[i];
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
	if (i >= len)
		// std::out_of_range is derived from std::exception, as required
		throw std::out_of_range("Array index out of range");
	return arr[i];
}

template <typename T>
T const &Array<T>::operator[](unsigned int i) const
{
	if (i >= len)
		throw std::out_of_range("Array index out of range");
	return arr[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return len;
}
