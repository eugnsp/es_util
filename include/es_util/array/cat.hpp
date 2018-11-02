#pragma once
#include <es_util/array/core.hpp>

#include <array>
#include <cstddef>
#include <type_traits>
#include <utility>

namespace es::util
{
namespace internal
{
template<typename Array1, typename Array2, std::size_t... indices1, std::size_t... indices2>
constexpr auto array_cat(Array1&& arr1, Array2&& arr2,
	std::index_sequence<indices1...>, std::index_sequence<indices2...>)
{
	using std::get;
	return make_array(get<indices1>(std::forward<Array1>(arr1))...,
		get<indices2>(std::forward<Array2>(arr2))...);
}
}

template<typename Array, typename... Arrays>
constexpr auto array_cat(Array&& arr, Arrays&&... arrs)
{
	if constexpr (sizeof...(Arrays) == 0)
		return std::forward<Array>(arr);
	else if constexpr (sizeof...(Arrays) == 1)
		return internal::array_cat(std::forward<Array>(arr), std::forward<Arrays>(arrs)...,
			std::make_index_sequence<array_size<Array>>{},
			std::make_index_sequence<array_size<Arrays...>>{});
	else
		return array_cat(std::forward<Array>(arr), array_cat(std::forward<Arrays>(arrs)...));
}
}