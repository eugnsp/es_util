#pragma once
#include <iterator>

namespace es_util
{
// Checks if the predicate returns true for all adjacent pairs of elements in the range,
// returns true if the predicate returns true for all pairs, false otherwise,
// returns true if the range contains less than two elements.
template<class Forward_iterator, class Predicate>
bool all_of_pairs(Forward_iterator begin, Forward_iterator end, Predicate pred)
{
	if (begin == end)
		return true;

	for (auto next = std::next(begin); next != end; ++begin, ++next)
		if (!pred(*begin, *next))
			return false;

	return true;
}

// Checks if the predicate returns true for at least one adjacent pair of elements
// in the range, returns true if the predicate returns true for at least one pair,
// false otherwise, returns false if the range contains less than two elements.
template<class Forward_iterator, class Predicate>
bool any_of_pairs(Forward_iterator begin, Forward_iterator end, Predicate pred)
{
	if (begin == end)
		return false;

	for (auto next = std::next(begin); next != end; ++begin, ++next)
		if (pred(*begin, *next))
			return true;

	return false;
}

// Checks if the predicate returns true for no adjacent pairs of elements
// in the range, returns true if the predicate returns true for no pairs,
// false otherwise, returns true if the range contains less than two elements.
template<class Forward_iterator, class Predicate>
bool none_of_pairs(Forward_iterator begin, Forward_iterator end, Predicate pred)
{
	if (begin == end)
		return true;

	for (auto next = std::next(begin); next != end; ++begin, ++next)
		if (pred(*begin, *next))
			return false;

	return true;
}
}