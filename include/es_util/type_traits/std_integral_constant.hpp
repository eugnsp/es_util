#pragma once

#include <type_traits>

namespace es_util
{
template<auto value>
using Std_integral_constant = std::integral_constant<decltype(value), value>;
}
