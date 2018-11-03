#pragma once
#include <es_util/algorithm/all_any_none_of_pairs.hpp>
#include <es_util/algorithm/find.hpp>
#include <es_util/algorithm/for_each_pair.hpp>
#include <es_util/algorithm/is_circ_permutations.hpp>
#include <es_util/algorithm/sort.hpp>
#include <es_util/type_traits.hpp>
#include <es_util/numeric.hpp>
#include <es_util/tuple.hpp>

#include <algorithm>
#include <array>
#include <cassert>
#include <cstddef>
#include <functional>
#include <iterator>
#include <numeric>
#include <type_traits>
#include <utility>

namespace es_util
{
// Computes the sum of the elements in the range <[first, last)>
// using the given binary function <op>.
template<typename T = void, typename Input_it, class Bin_op>
auto accumulate_non_empty(Input_it first, Input_it last, Bin_op op)
{
	using Value = es_util::Non_void_t_or<T, typename std::iterator_traits<Input_it>::value_type>;

	assert(first != last);
	Value init = std::move(*first);
	return std::accumulate(++first, last, std::move(init), op);
}

// Computes the sum of the elements in the range <[first, last)>.
template<typename T = void, typename Input_it>
auto accumulate_non_empty(Input_it first, Input_it last)
{
	return es_util::accumulate_non_empty<T>(first, last, std::plus<>{});
}
}