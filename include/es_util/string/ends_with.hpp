#pragma once
#include <functional>
#include <string_view>

namespace es_util
{
// Checks if a string ends with a given substring
template<class Binary_predicate>
bool ends_with(std::string_view str, std::string_view ending, Binary_predicate pred)
{
	return ending.length() <= str.length() &&
		   std::equal(ending.rbegin(), ending.rend(), str.rbegin(), pred);
}

inline bool ends_with(std::string_view str, std::string_view ending)
{
	return es_util::ends_with(str, ending, std::equal_to<>{});
}
} // namespace es_util