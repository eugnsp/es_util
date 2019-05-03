#pragma once
#include <type_traits>

namespace es_util
{
template<typename...>
struct Always_false : std::false_type
{};

template<typename... Ts>
inline constexpr bool always_false = Always_false<Ts...>::value;
} // namespace es_util
