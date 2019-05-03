#pragma once
#include <es_util/type_traits/all_any_none.hpp>

#include <type_traits>

namespace es_util
{
template<typename S, typename T, typename... Ts>
struct Is_one_of : Any<std::is_same_v<S, T>, std::is_same_v<S, Ts>...>
{};

template<typename S, typename T, typename... Ts>
inline constexpr bool is_one_of = Is_one_of<S, T, Ts...>::value;
} // namespace es_util
