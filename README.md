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

### Containers

#### Fenwick tree (binary indexed tree)

```cpp
namespace es_util
{
template<typename T>
class Fenwick_tree
{
public:
	using Value = T;

	Fenwick_tree();
	Fenwick_tree(std::size_t size);

	template<class Input_iterator1, class Input_iterator2>
	Fenwick_tree(Input_iterator1 first, Input_iterator2 last);

	Fenwick_tree(std::initializer_list<Value>);

	void reset(std::size_t size);

	template<class Input_iterator1, class Input_iterator2>
	void reset(Input_iterator1 first, Input_iterator2 last);

	std::size_t size() const;
	bool is_empty() const;

	Value operator[](std::size_t) const;

	Value sum(std::size_t first, std::size_t last) const;
	Value sum(std::size_t) const;
	Value sum() const;

	std::size_t lower_bound(Value) const;
	std::size_t upper_bound(Value) const;

	void add(std::size_t, const Value&);
	void set(std::size_t, const Value&);
};
}
```

[Detailed description](doc/FENWICK_TREE.md)
