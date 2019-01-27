#pragma once

#include <cstddef>
#include <type_traits>
#include <utility>

namespace es_util
{
template<class T>
struct Remove_cvref_impl
{
	using Type = std::remove_cv_t<std::remove_reference_t<T>>;
};

template<class T>
using Remove_cvref = typename Remove_cvref_impl<T>::Type;

//////////////////////////////////////////////////////////////////////////

// Template used to exclude specific arguments from deduction
template<class T>
struct Identity_fn
{
	using Type = T;
};

template<class T>
using Identity = typename Identity_fn<T>::Type;

//////////////////////////////////////////////////////////////////////////

template<typename T, typename Default>
using Non_void_t_or = std::conditional_t<std::is_void_v<T>, Default, T>;

//////////////////////////////////////////////////////////////////////////

// Checks whether all values are the same
template<typename T, T t_value, T... t_values>
struct Same_values : All<(t_value == t_values)...>
{};

template<typename T, T t_value, T... t_values>
inline constexpr bool same_values_v = Same_values<T, t_value, t_values...>::value;

//////////////////////////////////////////////////////////////////////////

// Returns the the first value in the pack
template<auto value, auto...>
struct First : std::integral_constant<decltype(value), value>
{};

template<auto... values>
inline constexpr auto first_v = First<values...>::value;

// Checks whether all values are the same (the value is true if the pack is empty)
template<auto value, auto... values>
inline constexpr auto all_same = (... && (value == values));

template<auto... values>
struct All_same : std::bool_constant<all_same<values...>>
{};

//////////////////////////////////////////////////////////////////////////

template<std::size_t index>
struct Index : std::integral_constant<std::size_t, index>
{};

//////////////////////////////////////////////////////////////////////////

template<typename T>
struct Is_trivially_relocatable :
	std::conjunction<std::is_trivially_move_constructible<T>, std::is_trivially_destructible<T>>
{};

template<typename T>
inline constexpr bool is_trivially_relocatable = Is_trivially_relocatable<T>::value;

template<typename T>
struct Is_memcpy_copyable :
	std::conjunction<std::is_trivially_copy_constructible<T>, std::is_trivially_copy_assignable<T>>
{};

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
} // namespace internal

template<class Sequence, typename Sequence::value_type offset>
using Offset_integer_sequence =
	typename internal::Offset_integer_sequence_impl<Sequence, offset>::Type;
} // namespace es_util
