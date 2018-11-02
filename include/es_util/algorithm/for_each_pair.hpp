#pragma once
#include <es_util/type_traits.hpp>
#include <es_util/numeric.hpp>
#include <es_util/tuple.hpp>

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <utility>

namespace es::util
{
// Applies a given function object to adjacent pairs of elements
// in the range [first, last), in order.
//
// Parameters:
//  first, last - the range to apply the function to,
//  func - the function object to be applied, the signature should be
//         equivalent to the following: void func(T& a, T& b);
//         the type T must be such that an object of type Fw_it_begin
//         can be dereferenced and then implicitly converted to T. 
//
// Return value:
//  the iterator pointing to the last element in the range,
//  first if the range contains less than two elements.
template<class Fw_it, class Fw_it_end, class Fn>
Fw_it for_each_pair(Fw_it first, Fw_it_end last, Fn&& fn)
{
	if (first == last)
		return first;

	auto next = std::next(first);
	while (next != last)
		fn(*first++, *next++);

	return first;
}

// Applies a given function object to adjacent pairs of elements
// in the range [first, first + n), in order.
//
// Parameters:
//  first - the beginning of the range to apply the function to,
//  n - the number of pairs to apply the function to
//  <func> - the function object to be applied, the signature should be
//           equivalent to the following: <void func(T& a, T& b);>.
//
// Return value:
//  the iterator pointing to the last element in the range,
//  <first> if the range contains less than two elements (n <= 0).
template<class Fw_it, typename N, class Fn>
Fw_it for_each_pair_n(Fw_it first, N n, Fn&& fn)
{
	auto next = first;
	for (N i = 0; i < n; ++i)
		fn(*first++, *++next);

	return first;
}

}