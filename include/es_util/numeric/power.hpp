#pragma once
#include <es_util/numeric/even_odd.hpp>

#include <cassert>
#include <type_traits>

namespace es_util
{
// Squares the argument
template<typename T>
constexpr T sq(T x)
{
	return x * x;
}

// Cubes the argument
template<typename T>
constexpr T cube(T x)
{
	return x * x * x;
}

// Returns the non-negative n-th power of the argument
template<typename T, typename Integral>
constexpr T int_pow(T x, Integral n)
{
	static_assert(std::is_integral_v<Integral>);
	assert(n >= 0);

	auto result = static_cast<T>(1);
	while (n)
	{
		if (is_odd(n))
			result *= x;
		n >>= 1;
		x *= x;
	}

	return result;
}

}