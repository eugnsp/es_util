#pragma once
#include <type_traits>

namespace es_util
{
// Returns the absolute value of the integral argument
template<typename Integral>
constexpr Integral iabs(Integral n)
{
	static_assert(std::is_integral_v<Integral>);
	return (n < 0) ? -n : n;
}

// Returns the absolute value of the integral argument
// with the result having the unsigned type
template<typename Integral>
constexpr auto unsigned_iabs(Integral n)
{
	static_assert(std::is_integral_v<Integral>);

	using Unsigned = std::make_unsigned_t<Integral>;
	const Unsigned un = static_cast<Unsigned>(n);
	return (n >= 0) ? un : (0 - un);
}
} // namespace es_util
