# Utilities library

## Synopsis

### Algorithms

```cpp
namespace es_util
{
template<class Forward_iterator1, class Forward_iterator2, class Fn>
Fw_it for_each_pair(Forward_iterator1 first, Forward_iterator2 last, Fn);

template<class Forward_iterator, typename N, class Fn>
Fw_it for_each_pair_n(Forward_iterator first, N, Fn)
}
```

[Detailed description](doc/ALGORITHM.md)

### Containers

#### Fenwick tree (binary indexed tree)

```cpp
namespace es_util
{
template<typename Value_, typename Size_ = std::size_t>
class Fenwick_tree
{
public:
	using Value = Value_;
	using Size = Size_;

	Fenwick_tree();
	Fenwick_tree(Size);
	Fenwick_tree(std::vector<Value>);

	template<class Input_iterator1, class Input_iterator2>
	Fenwick_tree(Input_iterator1 first, Input_iterator2 last);

	Fenwick_tree(std::initializer_list<Value>);

	// Capacity

	bool is_empty() const;
	Size size() const;
	Size capacity() const;

	// Element access

	Value operator[](Size) const;

	template<class Random_access_iterator>
	void get(Random_access_iterator);

	Value sum(Size first, Size last) const;
	Value sum(Size) const;
	Value sum() const;

	Size lower_bound(Value) const;
	Size upper_bound(Value) const;

	// Modifiers

	void reset(Size);
	void reset(std::vector<Value>);

	template<class Input_iterator1, class Input_iterator2>
	void reset(Input_iterator1 first, Input_iterator2 last);

	void add(Size, const Value&);
	void set(Size, const Value&);

	void push(const Value&);
	void pop();
};
}
```

[Detailed description](doc/FENWICK_TREE.md)

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
