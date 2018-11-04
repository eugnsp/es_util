#pragma once
#include <array>
#include <cstddef>
#include <type_traits>
#include <utility>

namespace es_util
{
namespace internal
{
template<typename T, std::size_t size, std::size_t... indices>
constexpr auto to_array_impl(T (&arr)[size], std::index_sequence<indices...>)
{
	return std::array<std::remove_cv_t<T>, size>{arr[indices]...};
}
}

// Creates an std::array from the built-in array
template<typename T, std::size_t size>
constexpr auto to_array(T (&arr)[size])
{
	return internal::to_array_impl(arr, std::make_index_sequence<size>{});
}
}