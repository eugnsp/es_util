# Utilities library

## Synopsis

### Algorithms

```
namespace es_util
{
template<class Fw_it, class Fw_it_end, class Fn>
Fw_it for_each_pair(Fw_it first, Fw_it_end last, Fn);

template<class Fw_it, typename N, class Fn>
Fw_it for_each_pair_n(Fw_it first, N, Fn)
}
```

[Detailed description](doc/ALGORITHM.md)

### Tuples

```cpp
namespace es_util
{
template<class Tuple>
inline constexpr auto tuple_size;

template<class Tuple, std::size_t i>
std::size_t tuple_element_offset();

template<class Pred, class... Tuples>
constexpr bool tuple_all_of(Pred, Tuples&&...);

template<class Pred, class... Tuples>
constexpr bool tuple_any_of(Pred, Tuples&&...);

template<class Pred, class... Tuples>
constexpr bool tuple_none_of(Pred, Tuples&&...);

template<class... Tuples>
auto tuple_forward_as_zipped(Tuples&&...);

template<class Fn, class... Tuples>
constexpr void tuple_for_each(Fn&&, Tuples&&...);

template<class Fn, class... Tuples>
constexpr auto tuple_map(Fn&&, Tuples&&...);
}
```

[Detailed description](doc/TUPLE.md)