#pragma once
#include <es_util/tuple/core.hpp>
#include <es_util/array/core.hpp>

#include <cstddef>
#include <array>
#include <tuple>
#include <type_traits>
#include <utility>

namespace es_util
{
namespace internal
{
template<class Tuple, std::size_t... indices>
constexpr auto tuple_to_array(Tuple&& tuple, std::index_sequence<indices...>)
{
	return make_array(std::get<indices>(std::forward<Tuple>(tuple))...);
}
}

template<class Tuple>
constexpr auto tuple_to_array(Tuple&& tuple)
{
	return internal::tuple_to_array(std::forward<Tuple>(tuple),
				internal::index_sequence_for_tuple<Tuple>);
}
}