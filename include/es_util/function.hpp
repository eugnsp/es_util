#pragma once
#include <algorithm>
#include <cstdint>
#include <cstddef>
#include <utility>
#include <string>
#include <sstream>
#include <iterator>
#include <type_traits>

namespace es::util
{
namespace internal
{
struct Identity_function
{
	template<typename T>
	constexpr decltype(auto) operator()(T&& v) const noexcept
	{
		return std::forward<T>(v);
	}
};
}

template<typename T>
T reverse_bytes(T value)
{
	const auto p = reinterpret_cast<char*>(&value);
	std::reverse(p, p + sizeof(T));
	return value;
}

template<class Iter>
std::string join_as_string(Iter begin, Iter end, std::string delim = ", ")
{
	std::stringstream ss;

	for (;;)
	{
		ss << *begin;
		++begin;
		if (begin != end)
			ss << delim;
		else
			break;
	}

	return ss.str();
}

template<class Iter, class Function = internal::Identity_function>
auto average(Iter begin, const Iter end, Function func = Function{})
{
	using Value = typename std::iterator_traits<Iter>::value_type;
	using Counter = typename std::iterator_traits<Iter>::difference_type;

	std::result_of_t<Function(Value)> result{};
	for (Counter n = 1; begin != end; ++begin, ++n)
		result += (func(*begin) - result) / static_cast<decltype(result)>(n);

	return result;
}

// Checks if a string ends with a given substring
bool ends_with(const std::string& str, const std::string& ending, bool case_sensitive = true);

// Returns size in bytes in a human readable form
std::string size_string(std::size_t size);

std::string compiler_and_mkl_info();
}