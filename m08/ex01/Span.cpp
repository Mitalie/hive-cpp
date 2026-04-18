#include <algorithm>
#include <stdexcept>
#include <vector>

#include "Span.hpp"

Span::~Span()
{
}

Span::Span(unsigned int n)
	: capacity(n), values(), sortedCount(0)
{
	values.reserve(capacity);
}

Span::Span(const Span &other)
	: capacity(other.capacity),
	  values(other.values),
	  sortedCount(other.sortedCount)
{
	values.reserve(capacity);
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		capacity = other.capacity;
		values = other.values;
		sortedCount = other.sortedCount;
	}
	return *this;
}

void Span::addNumber(int v)
{
	if (values.size() == capacity)
		throw std::out_of_range("Span is full");
	values.push_back(v);
}

static unsigned int delta(int a, int b)
{
	// Signed overflow is undefined behavior, but unsigned wraparound is safe
	// and produces the correct result for absolute difference.
	// Both positive: no wraparound happens
	// Both negative: both wrap around on cast, difference remains unchanged
	// Smaller number negative: negative number wraps around on cast and becomes
	//   bigger than the other; subtraction result is mathematically negative
	//   but wraps around to positive, cancelling out the first wraparound.
	return (a > b) ? ((unsigned int)a - (unsigned int)b)
				   : ((unsigned int)b - (unsigned int)a);
}

unsigned int Span::shortestSpan() const
{
	if (values.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	// By sorting the array, the shortest span will be between adjacent elements
	// and we avoid O(n^2) scaling of checking all pairs.
	ensureSorted();
	unsigned int minSpan = delta(values[1], values[0]);
	for (unsigned int i = 2; i < values.size(); ++i)
	{
		unsigned int span = delta(values[i], values[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

unsigned int Span::longestSpan() const
{
	if (values.size() < 2)
		throw std::logic_error("Not enough numbers to find a span");
	// We could scan linearly for min and max, but since we want to keep the
	// values sorted for shortestSpan, we can just use first and last element.
	ensureSorted();
	return delta(values.back(), values.front());
}

void Span::ensureSorted() const
{
	if (sortedCount < values.size())
	{
		// Sort only the new elements and merge with the already sorted part
		typedef std::vector<int>::iterator it_type;
		it_type begin = values.begin();
		it_type middle = values.begin() + sortedCount;
		it_type end = values.end();
		std::sort(middle, end);
		std::inplace_merge(begin, middle, end);
		sortedCount = values.size();
	}
}
