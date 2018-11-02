#pragma once
#include <es_util/tuple/core.hpp>
#include <es_util/type_traits.hpp>

#include <cstddef>
#include <tuple>

namespace es::util
{
namespace internal
{
template<std::size_t index, class... Tuples>
auto tuple_forward_as_zipped(Tuples&&... tuples)
{
	using std::get;
	return std::forward_as_tuple(get<index>(
		std::forward<Tuples>(tuples))...);
}

template<std::size_t... indices, class... Tuples>
auto tuple_forward_as_zipped(std::index_sequence<indices...>, Tuples&&... tuples)
{ 
	return std::make_tuple(tuple_forward_as_zipped<indices>(
		std::forward<Tuples>(tuples)...)...);
}
}

// Constructs a tuple of tuples holding rvalue references to first, second, etc.
// elements of a list of tuples ("zips" tuples for forwarding)
template<class... Tuples>
auto tuple_forward_as_zipped(Tuples&&... tuples)
{
 	static_assert(sizeof...(Tuples) > 0);
 	static_assert(all_same<tuple_size<Tuples>...>, "All tuples must have the same size");

	return internal::tuple_forward_as_zipped(
		internal::index_sequence_for_tuple<Head_t<Tuples...>>,
		std::forward<Tuples>(tuples)...);
}
}