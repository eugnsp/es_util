#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

namespace es_util
{
/*
namespace internal
{
template<std::size_t n, auto init, decltype(init)... values>
struct inline constexpr auto sum_values_n = (init + ... + values);
}
*/

/*
template<auto init, decltype(init)... values>
inline constexpr auto sum_values = (init + ... + values);

template<std::size_t n, auto init, auto... values>
inline constexpr auto sum_values_n = (init + ... + values);

template<typename T, std::size_t n, T value, T... values>
struct Sum_first_n_values :
	std::integral_constant<T, value + Sum_first_n_values<T, n - 1, values...>::value>
{};

template<typename T, T value, T... values>
struct Sum_first_n_values<T, 1, value, values...> : std::integral_constant<T, value>
{};

template<typename T, std::size_t n, T value, T... values>
inline constexpr T sum_first_n_values_v = Sum_first_n_values<T, n, value, values...>::value;
*/
} // namespace es_util