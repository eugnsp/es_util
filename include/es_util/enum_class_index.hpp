#pragma once

#define ES_UTIL_ENUM_CLASS_INDEX_TYPE(Index_type, Index_name, ...)                                 \
	enum class Index_name : Index_type                                                             \
	{                                                                                              \
		__VA_ARGS__                                                                                \
	};                                                                                             \
                                                                                                   \
	inline constexpr Index_type operator*(Index_name index)                                        \
	{                                                                                              \
		return static_cast<Index_type>(index);                                                     \
	}                                                                                              \
                                                                                                   \
	template<typename N>                                                                           \
	inline constexpr Index_name& operator+=(Index_name& index, N n)                                \
	{                                                                                              \
		index = static_cast<Index_name>(*index + n);                                               \
		return index;                                                                              \
	}                                                                                              \
                                                                                                   \
	template<typename N>                                                                           \
	inline constexpr Index_name& operator-=(Index_name& index, N n)                                \
	{                                                                                              \
		index = static_cast<Index_name>(*index - n);                                               \
		return index;                                                                              \
	}                                                                                              \
                                                                                                   \
	template<typename N>                                                                           \
	inline constexpr Index_name operator+(Index_name index, N n)                                   \
	{                                                                                              \
		return index += n;                                                                         \
	}                                                                                              \
                                                                                                   \
	template<typename N>                                                                           \
	inline constexpr Index_name operator-(Index_name index, N n)                                   \
	{                                                                                              \
		return index -= n;                                                                         \
	}                                                                                              \
                                                                                                   \
	inline constexpr Index_name& operator++(Index_name& index)                                     \
	{                                                                                              \
		return index += 1;                                                                         \
	}                                                                                              \
                                                                                                   \
	inline constexpr Index_name operator++(Index_name& index, int)                                 \
	{                                                                                              \
		const auto old = index;                                                                    \
		++index;                                                                                   \
		return old;                                                                                \
	}                                                                                              \
                                                                                                   \
	inline constexpr Index_name& operator--(Index_name& index)                                     \
	{                                                                                              \
		return index -= 1;                                                                         \
	}                                                                                              \
                                                                                                   \
	inline constexpr Index_name operator--(Index_name& index, int)                                 \
	{                                                                                              \
		const auto old = index;                                                                    \
		++index;                                                                                   \
		return old;                                                                                \
	}
