#pragma once
#include <functional>
#include <utility>

namespace es_util
{
// Sorts two elements, preserving relative order of the elements
template<typename T, class Compare>
void sort(T& x, T& y, Compare cmp)
{
	using std::swap;
	if (cmp(y, x))
		swap(x, y);
}

// Sorts two elements, preserving relative order of the elements
template<typename T>
void sort(T& x, T& y)
{
	es_util::sort(x, y, std::less<>{});
}

// Sorts two elements, preserving relative order of the elements
template<typename T, class Compare>
std::pair<const T&, const T&> sorted(const T& x, const T& y, Compare cmp)
{
	if (cmp(y, x))
		return {y, x};
	else
		return {x, y};
}

// Sorts two elements, preserving relative order of the elements
template<typename T>
std::pair<const T&, const T&> sorted(const T& x, const T& y)
{
	return es_util::sorted(x, y, std::less<>{});
}
} // namespace es_util
