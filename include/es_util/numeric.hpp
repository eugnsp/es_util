#pragma once
#include <array>
#include <cstddef>
#include <type_traits>

namespace es_util
{
namespace internal
{
template<typename T, typename S, std::size_t size, std::size_t... ii>
constexpr T accumulate(const std::array<S, size>& array, T init, std::index_sequence<ii...>)
{
	return (init + ... + array[ii]);
}
}

// Returns the sum of the given value (init) and elements in the (array)
template<typename T, typename S, std::size_t size>
constexpr T accumulate(const std::array<S, size>& array, T init)
{
	return internal::accumulate(array, init, std::make_index_sequence<size>{});
}

// Returns the sum of the given value (init) and first (n) elements in the (array)
template<std::size_t n, typename T, typename S, std::size_t size>
constexpr T accumulate_first_n(const std::array<S, size>& array, T init)
{
	static_assert(n <= size, "Too many values to accumulate");
	return internal::accumulate(array, init, std::make_index_sequence<n>{});
}


}