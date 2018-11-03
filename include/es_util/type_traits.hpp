#pragma once
#include <cstddef>
#include <type_traits>
#include <utility>

namespace es_util
{
template<class T>
struct Remove_cvref
{
	using Type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T>
using Remove_cvref_t = typename Remove_cvref<T>::Type;

//////////////////////////////////////////////////////////////////////////

// Template used to exclude specific arguments from deduction
template<class T>
struct Identity
{
	using Type = T;
};

template<class T>
using Identity_t = typename Identity<T>::Type;

//////////////////////////////////////////////////////////////////////////

template<typename T, typename Default>
using Non_void_t_or = std::conditional_t<std::is_void_v<T>, Default, T>;

//////////////////////////////////////////////////////////////////////////

// Checks whether all bool values are true (true if the pack is empty)
template<bool... values>
struct All : std::conjunction<std::bool_constant<values>...> { };

// Checks whether any bool value is true (false if the pack is empty)
template<bool... values>
struct Any : std::disjunction<std::bool_constant<values>...> { };

template<bool... values>
inline constexpr bool all_v = All<values...>::value;

template<bool... values>
inline constexpr bool any_v = Any<values...>::value;

//////////////////////////////////////////////////////////////////////////

// Checks whether all values are the same
template<typename T, T t_value, T... t_values>
struct Same_values : All<(t_value == t_values)...>
{ };

template<typename T, T t_value, T... t_values>
inline constexpr bool same_values_v = Same_values<T, t_value, t_values...>::value;

//////////////////////////////////////////////////////////////////////////

template<typename T, std::size_t n, T value, T... values>
struct Sum_first_n_values :
	std::integral_constant<T, value + Sum_first_n_values<T, n - 1, values...>::value> { };

template<typename T, T value, T... values>
struct Sum_first_n_values<T, 1, value, values...> : std::integral_constant<T, value> { };

template<typename T, std::size_t n, T value, T... values>
inline constexpr T sum_first_n_values_v = Sum_first_n_values<T, n, value, values...>::value;

//////////////////////////////////////////////////////////////////////////

// Returns the the first value in the pack
template<auto value, auto...>
struct First : std::integral_constant<decltype(value), value> { };

template<auto... values>
inline constexpr auto first_v = First<values...>::value;

// Checks whether all values are the same (the value is true if the pack is empty)
template<auto value, auto... values>
inline constexpr auto all_same = (... && (value == values));

template<auto... values>
struct All_same : std::bool_constant<all_same<values...>> { };

//////////////////////////////////////////////////////////////////////////

// Returns the type of the n-th element in the pack
template<std::size_t n, typename T, typename... Ts>
struct Nth
{
	using Type = typename Nth<n - 1, Ts...>::Type;
};

template<typename T, typename... Ts>
struct Nth<0, T, Ts...>
{
	using Type = T;
};

// Returns the type of the n-th element in the pack
template<std::size_t i, class... Ts>
using Nth_t = typename Nth<i, Ts...>::Type;

template<typename T, typename...>
struct Head
{
	using Type = T;
};

template<typename... Ts>
using Head_t = typename Head<Ts...>::Type;

//////////////////////////////////////////////////////////////////////////

template<typename T, typename... Ts>
struct Index;

template<typename T, typename... Ts>
struct Index<T, T, Ts...> : std::integral_constant<std::size_t, 0> { };

template<typename T, typename NT, typename... Ts>
struct Index<T, NT, Ts...> : std::integral_constant<std::size_t, 1 + Index<T, Ts...>::value> { };

template<typename T, typename... Ts>
inline constexpr std::size_t index_v = Index<T, Ts...>::value;

//////////////////////////////////////////////////////////////////////////

template<std::size_t index>
using Index_t = std::integral_constant<std::size_t, index>;

//////////////////////////////////////////////////////////////////////////

template<typename T>
struct Is_trivially_relocatable : std::conjunction<
	std::is_trivially_move_constructible<T>, std::is_trivially_destructible<T>> { };

template<typename T>
inline constexpr bool is_trivially_relocatable = Is_trivially_relocatable<T>::value;

template<typename T>
struct Is_memcpy_copyable : std::conjunction<
	std::is_trivially_copy_constructible<T>, std::is_trivially_copy_assignable<T>> { };

//////////////////////////////////////////////////////////////////////////

template<bool f, typename T>
using Add_const_if = std::conditional_t<f, std::add_const_t<T>, T>;

template<typename T>
using Add_const_to_pointer = std::add_pointer_t<std::add_const_t<std::remove_pointer_t<T>>>;

template<bool f, typename T>
using Add_const_to_pointer_if = std::add_pointer_t<Add_const_if<f, std::remove_pointer_t<T>>>;

//////////////////////////////////////////////////////////////////////////

namespace internal
{
template<class Sequence, auto offset>
struct Offset_integer_sequence_impl;

template<typename T, T... is, auto offset>
struct Offset_integer_sequence_impl<std::integer_sequence<T, is...>, offset>
{
	using Type = std::integer_sequence<T, (is + offset)...>;
};
}

template<class Sequence, typename Sequence::value_type offset>
using Offset_integer_sequence = 
	typename internal::Offset_integer_sequence_impl<Sequence, offset>::Type;
}