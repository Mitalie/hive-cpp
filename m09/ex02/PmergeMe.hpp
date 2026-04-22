#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

template <typename T>
class PmergeMe
{
public:
	// Sort collection using the merge-insertion sort algorithm
	template <typename Coll>
	static void sort(Coll &coll);

private:
	// No instances, static functions only
	~PmergeMe();
	PmergeMe();
	PmergeMe(const PmergeMe &);
	PmergeMe &operator=(const PmergeMe &);

	// Helper class for recursive pairing and sorting
	class Pair
	{
	public:
		~Pair();
		Pair(const Pair &);
		Pair(const T &upperValue, size_t upperIdx, size_t lowerIdx);
		Pair(const Pair &inner, size_t upperIdx, size_t lowerIdx);
		Pair &operator=(const Pair &);
		bool operator<(const Pair &other) const;
		size_t getUpperIdx() const;
		size_t getLowerIdx() const;

	private:
		T upperValue;
		size_t upperIdx;
		size_t lowerIdx;
	};
};

// Template implementation dragons below

template <typename T>
PmergeMe<T>::Pair::~Pair()
{
}

template <typename T>
PmergeMe<T>::Pair::Pair(const Pair &other)
	: upperValue(other.upperValue), upperIdx(other.upperIdx), lowerIdx(other.lowerIdx)
{
}

template <typename T>
typename PmergeMe<T>::Pair &PmergeMe<T>::Pair::operator=(const Pair &other)
{
	upperValue = other.upperValue;
	upperIdx = other.upperIdx;
	lowerIdx = other.lowerIdx;
	return *this;
}

template <typename T>
PmergeMe<T>::Pair::Pair(const T &upperValue, size_t upperIdx, size_t lowerIdx)
	: upperValue(upperValue), upperIdx(upperIdx), lowerIdx(lowerIdx)
{
}

template <typename T>
PmergeMe<T>::Pair::Pair(const PmergeMe<T>::Pair &inner, size_t upperIdx, size_t lowerIdx)
	: upperValue(inner.upperValue), upperIdx(upperIdx), lowerIdx(lowerIdx)
{
}

template <typename T>
bool PmergeMe<T>::Pair::operator<(const PmergeMe<T>::Pair &other) const
{
	return upperValue < other.upperValue;
}

template <typename T>
size_t PmergeMe<T>::Pair::getUpperIdx() const
{
	return upperIdx;
}

template <typename T>
size_t PmergeMe<T>::Pair::getLowerIdx() const
{
	return lowerIdx;
}

template <typename T>
template <typename Coll>
void PmergeMe<T>::sort(Coll &coll)
{
	if (coll.size() <= 1)
		return;
	// Consider each groupSize consecutive elements a single item, handled together.

	// Form pairs of items and sort the two items in each pair based on their last elements.
	// Together each pair forms a larger item for the next level of recursion.
	// If the number of items is odd, the last item is left unpaired and will be handled at the end.
	size_t numPairs = coll.size() / 2;
	std::vector<Pair> pairs;
	pairs.reserve(numPairs);
	for (size_t i = 0; i < numPairs; ++i)
	{
		size_t first = 2 * i;
		size_t second = 2 * i + 1;
		if (coll[second] < coll[first])
			pairs.push_back(Pair(coll[first], first, second));
		else
			pairs.push_back(Pair(coll[second], second, first));
	}

	// Recursively sort the larger items. This establishes the correct order between the upper items
	// of each pair, but only an upper bound for the lower items.
	sort(pairs);

	// Now we shift the lower items into their correct positions using a binary insertion sort. The
	// pairing to already sorted upper items enables an additional optimization: we can insert the
	// lower items in an order that minimizes the search depth for each insertion. A binary search
	// of depth N can choose correct position among up to 2^N - 1 already sorted items. The already
	// sorted items are the upper items up to but not including the current index, and the already
	// inserted lower items.

	// The naive insertion order is to insert the lower items in the order of their indices. The
	// search space grows by two with every insertion: the inserted item, and one more upper item
	// as we increase the index.
	// Num inserted: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,...,31,32
	// Selected idx: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,...,31,32
	// Search space: 0, 2, 4, 6, 8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,42,...,62,64
	// Search depth: 0, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6,..., 6, 7

	// What if we insert in reverse order? Lower items that have not been inserted yet are not part
	// of the search space even if they have a lower index than the current item. After each
	// insertion, the number of sorted items grows, but as we move to lower indices, we consider
	// fewer upper items because upper items of same and higher indices are guaranteed to come after
	// the current item.

	// If we start at the very last index, the search depth is large from the beginning. Instead we
	// want to start at the lowest possible depth, but the largest possible index for that depth.
	// We insert all available lower items at that depth, and then move to the next depth.
	// Num inserted: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16,17,18,19,20,21,...,42,43
	// Search depth: 0, 2, 2, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6,..., 6, 7
	// Search space: 0, 3, 3, 7, 7,15,15,15,15,15,15,31,31,31,31,31,31,31,31,31,31,63,...,63,127
	// Selected idx: 0, 2, 1, 4, 3,10, 9, 8, 7, 6, 5,20,19,18,17,16,15,14,13,12,11,42,...,21,84

	// The selected index for insertions can be found using the Jacobsthal sequence, which is
	// defined as J(0) = 0, J(1) = 1, and J(n) = J(n-1) + 2*J(n-2) for n > 1. The sequence starts
	// 0, 1, 1, 3, 5, 11, 21, 43, 85, ... and each descending run of indices is (J(n), J(n-1)].

	// Create a separate collection for the output to avoid invalidating the indices stored in the
	// pairs. We later swap the contents into the reference output.
	Coll out;
	out.reserve(coll.size());
	// The first lower item is already in the correct position, so copy it to output already.
	out.push_back(coll[pairs[0].getLowerIdx()]);

	// First iteration will update the search area to 3 and lowerIdx to 3 - 1. We let the loop
	// code update them instead of setting here to benefit from the bounds checking in the loop.
	size_t lastJacobsthal = 1;
	size_t currJacobsthal = 1;
	size_t lowerIdx = 1;
	size_t upperIdx = 0;
	size_t searchArea = 1;
	// Handle lower items from all pairs in the optimal order
	for (size_t i = 1; i < numPairs; ++i)
	{
		// Next search area, calculate new highest index for optimal insertion
		if (lowerIdx == lastJacobsthal)
		{
			lowerIdx = currJacobsthal + 2 * lastJacobsthal;
			lastJacobsthal = currJacobsthal;
			currJacobsthal = lowerIdx;
			lowerIdx = std::min(lowerIdx, numPairs);
			// Push upper items for the next search area
			while (upperIdx < lowerIdx)
			{
				out.push_back(coll[pairs[upperIdx].getUpperIdx()]);
				++upperIdx;
			}
			searchArea = std::min(searchArea * 2 + 1, out.size());
		}
		--lowerIdx;
		// Binary search and insertion for the current lower item
		typename Coll::iterator insertPos = std::upper_bound(out.begin(), out.begin() + searchArea, coll[pairs[lowerIdx].getLowerIdx()]);
		out.insert(insertPos, coll[pairs[lowerIdx].getLowerIdx()]);
	}
	// Push the last upper item which comes after the last lower item
	if (upperIdx < lowerIdx)
		out.push_back(coll[pairs[upperIdx].getUpperIdx()]);
	// Insert the unpaired item if there is one
	if (coll.size() % 2 == 1)
	{
		typename Coll::iterator insertPos = std::upper_bound(out.begin(), out.end(), coll.back());
		out.insert(insertPos, coll.back());
	}
	coll.swap(out);
}
