#pragma once
#include <cstddef>

namespace es_util
{
namespace internal
{
// Returns the n-th type in the pack
template<std::size_t n, typename T, typename... Ts>
struct Nth_impl
{
	using Type = typename Nth_impl<n - 1, Ts...>::Type;
};

template<typename T, typename... Ts>
struct Nth_impl<0, T, Ts...>
{
	using Type = T;
};
}

// Returns the n-th type in the pack
template<std::size_t n, class... Ts>
using Nth = typename internal::Nth_impl<n, Ts...>::Type;

// Returns the first type in the pack
template<typename T, typename... Ts>
using Head = T;
}