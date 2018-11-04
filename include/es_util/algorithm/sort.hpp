#pragma once
#include <functional>
#include <utility>

namespace es_util
{
// Sorts two elements, preserving relative order of the elements
template<typename T, class Compare>
void sort2(T& x, T&y, Compare cmp)
{
	using std::swap;
	if (cmp(y, x))
		swap(x, y);
}

// Sorts two elements, preserving relative order of the elements
template<typename T>
void sort2(T& x, T&y)
{
	es_util::sort2(x, y, std::less<>{});
}
}