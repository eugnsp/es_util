#pragma once
#include <es_util/tuple/core.hpp>

#include <es_util/tuple/all_any_none.hpp>
#include <es_util/tuple/for_each.hpp>
#include <es_util/tuple/forward_as_zipped.hpp>
#include <es_util/tuple/map.hpp>
#include <es_util/tuple/to_array.hpp>

namespace es::util
{
namespace internal
{
template<std::size_t... is>
std::tuple<std::integral_constant<std::size_t, is>...> make_index_tuple(std::index_sequence<is...>);
}

template<std::size_t size>
using Make_index_tuple = decltype(internal::make_index_tuple(std::make_index_sequence<size>{}));
}
