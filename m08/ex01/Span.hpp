#pragma once

#include <vector>

class Span
{
public:
	~Span();
	Span(unsigned int n);
	Span(const Span &);
	Span &operator=(const Span &);

	void addNumber(int v);
	unsigned int shortestSpan() const;
	unsigned int longestSpan() const;

private:
	// Default constructor not allowed, capacity required
	Span();

	unsigned int capacity;

	// mutable allows modification in const methods, used for lazy sorting
	mutable std::vector<int> values;
	mutable unsigned int sortedCount;
	void ensureSorted() const;
};
