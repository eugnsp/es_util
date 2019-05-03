#pragma once
#include <type_traits>

namespace es_util
{
template<typename T>
struct Is_const_reference :
	std::conjunction<std::is_reference<T>, std::is_const<std::remove_reference<T>>>
{};

template<typename T>
inline constexpr bool is_const_reference = Is_const_reference<T>::value;
} // namespace es_util
