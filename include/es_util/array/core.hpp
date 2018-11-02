#pragma once
#include <array>
#include <tuple>
#include <type_traits>
#include <utility>

namespace es::util
{
template<class Array>
inline constexpr auto array_size = std::tuple_size_v<std::remove_reference_t<Array>>;

template<typename... Ts>
constexpr auto make_array(Ts&&... values)
{
	using T = std::common_type_t<Ts...>;
	return std::array<T, sizeof...(Ts)>{static_cast<T>(std::forward<Ts>(values))...};
}
}