# Utilities library

Namespace: `es_util`

## Algorithms

### `for_each_pair`
**Applies a function object to adjacent pairs of elements in a range**

```cpp
template<class Fw_it, class Fw_it_end, class Fn>
Fw_it for_each_pair(Fw_it first, Fw_it_end last, Fn fn);
```

Applies the given function object `fn` to adjacent pairs of elements in the range [`first`, `last`), in order.

*Parameters:*
* `first`, `last` - the range to apply the function object to,
* `fn` - the function object to be applied, the signature should be equivalent to the following: `void func(T& a, T& b);`; the type `T` must be such that an object of type `Fw_it` can be dereferenced and then implicitly converted to `T`. 

*Return value:*
the iterator pointing to the last element in the range; `first` if the range contains less than two elements.

*Example:*
```cpp
std::vector v{1, 2, 3, 4};
for_each_pair(v.begin(), v.end(), 
    [](int a, int b) { std::cout << '(' << a << ',' << b << ')'; });
// Outputs: (1,2)(2,3)(3,4)
```

---

### `for_each_pair_n`
**Applies a function object to adjacent pairs of elements in a range**

```cpp
template<class Fw_it, typename N, class Fn>
Fw_it for_each_pair_n(Fw_it first, N n, Fn fn)
```

Applies the given function object `fn` to adjacent pairs of elements in the range [`first`, `first + n`), in order.

*Parameters:*
* `first` - the beginning of the range to apply the function object to,
* `n` - the number of pairs to apply the function object to,
* `fn` - the function object to be applied, the signature should be equivalent to the following: `void func(T& a, T& b);`; the type `T` must be such that an object of type `Fw_it` can be dereferenced and then implicitly converted to `T`. 

*Return value:*
the iterator pointing to the last element in the range; `first` if the range contains less than two elements (`n` <= 0).

*Example:*
```cpp
std::vector v{1, 2, 3, 4};
for_each_pair_n(v.begin(), 2,
    [](int a, int b) { std::cout << '(' << a << ',' << b << ')'; });
// Output: (1,2)(2,3)
```

## Tuples

### `tuple_size`
**Gives the number of elements in a tuple**

```cpp
template<class Tuple>
inline constexpr auto tuple_size;
```

Variable template giving the number of elements in the tuple as a compile-time constant expression.

*Template parameters:*
* `Tuple` - any type accepted by `std::tuple_size`, possibly ref-qualified.

---

### `tuple_element_offset`
**Returns an offset from the beginning of a tuple to its member**

```cpp
template<class Tuple, std::size_t i>
std::size_t tuple_element_offset();
```

Returns the offset, in bytes, from the beginning of the tuple to its `i`-th member, including padding if any.

*Template parameters:*
* `Tuple` - the tuple type (possibly ref-qualified) to calculate the offset in,
* `i` - the index of the member to calculate the offset of.

*Note:*
The implementation has undefined behaviour, but works on many compilers. Use with care.

*Example:*
```cpp
using T = std::tuple<int, double>;
std::size_t offset_i = tuple_element_offset<T, 0>();
std::size_t offset_d = tuple_element_offset<T, 1>();
// Possible values: offset_i = 8, offset_d = 0
```

### `tuple_all_of`, `tuple_any_of`, `tuple_none_of`
**Checks whether a predicate returns `true` for all, any or none first, second, etc. elements of a list tuples**

```cpp
// 1.
template<class Pred, class... Tuples>
constexpr bool tuple_all_of(Pred pred, Tuples&&... tuples);
// 2.
template<class Pred, class... Tuples>
constexpr bool tuple_any_of(Pred pred, Tuples&&... tuples);
// 3.
template<class Pred, class... Tuples>
constexpr bool tuple_none_of(Pred pred, Tuples&&... tuples);
```

1. Checks whether the `m`-ary predicate `pred` returns `true` for all first, second, etc. elements of the list `tuples` of `m` tuples, all having the same size `n`.
2. Checks whether the `m`-ary predicate `pred` returns `true` for any first, second, etc. elements of the list `tuples` of `m` tuples, all having the same size `n`.
3. Checks whether the `m`-ary predicate `pred` returns `true` for no first, second, etc. elements of the list `tuples` of `m` tuples, all having the same size `n`.

*Parameters:*
* `pred` - the predicate that accepts every sequence of `i`-th elements of tuples, 
* `tuples` - the list of zero or more tuples of the same size `n`.

*Return value:*
1. `true` if the predicate called as `pred(std::get<i>(std::forward<Tuples>(tuples))...)` returns `true` for all `i = 0, ..., n - 1`, and `false` otherwise; returns `true` if `tuples` is an empty list or `tuples` are empty.
2. `true` if the predicate called as `pred(std::get<i>(std::forward<Tuples>(tuples))...)` returns `true` for any `i = 0, ..., n - 1`, and `false` otherwise; returns `false` if `tuples` is an empty list or `tuples` are empty.
3. `true` if the predicate called as `pred(std::get<i>(std::forward<Tuples>(tuples))...)` returns `true` for no `i = 0, ..., n - 1`, and `false` otherwise; returns `true` if `tuples` is an empty list or `tuples` are empty.

*Example:*
```cpp
std::tuple t1(1, 2, 3);
std::tuple t2('a', 'b', 'c');

bool z1 = tuple_all_of(
    [](int x) { return x == 1; }, t1);
assert(z1 == false);

bool z2 = tuple_all_of(
    [](int x, char y) { return x == 1 && y == 'a'; }, t1, t2);
assert(z2 == false);
```

---

### `tuple_forward_as_zipped`
**Constructs a tuple of tuples holding rvalue references to first, second, etc. elements of a list of tuples ("zips" tuples for forwarding)**

```cpp
template<class... Tuples>
auto tuple_forward_as_zipped(Tuples&&... tuples);
```
Constructs the tuple of `n` tuples holding rvalue references to first, second, etc. elements of the given list `tuples` of tuples, all having the same size `n`.

*Parameters:*
* `tuples` - the list of one or more tuples of the same size.

*Return value:*
`std::tuple<std::tuple<...>, std::tuple<...>, ...>`, where each internal `i`-th tuple is constructed by `std::forward_as_tuple(std::get<i>(std::forward<Tuples>(tuples))...)` for all `i = 0, ..., n - 1`.

*Example:*
```cpp
std::tuple<int, char> t1;
auto z = tuple_forward_as_zipped(t1, std::tuple<double, float>{});
// decltype(z) = std::tuple<std::tuple<int&, double&&>, std::tuple<char&, float&&>>
```

---

### `tuple_for_each`
**Applies a function object to first, second, etc. elements of a list tuples**

```cpp
template<class Fn, class... Tuples>
constexpr void tuple_for_each(Fn&& fn, Tuples&&... tuples);
```

Applies the given `m`-ary function object `fn` to first, second, etc. elements of the list `tuples` of `m` tuples, all having the same size `n`. The function object is applied to `std::get<i>(std::forward<Tuples>(tuples))...)` for all `i = 0, ..., n - 1`.

*Parameters:*
* `fn` - the function object that accepts every sequence of `i`-th elements of tuples, 
* `tuples` - the list of one or more tuples of the same size.

*Example:*
```cpp
std::tuple t1(1, 2, 3);
std::tuple t2('a', 'b', 'c');

tuple_for_each(
    [](int x, char y) { std::cout << '(' << x << ',' << y <<')'; }, t1, t2);
// Output: (1,a)(2,b)(3,c)
```

---

### `tuple_map`
**Applies a function object to first, second, etc. elements of a list tuples and returns a tuple of results**

```cpp
template<class Fn, class... Tuples>
constexpr auto tuple_map(Fn&& fn, Tuples&&... tuples);
```

Applies the given `m`-ary function object `fn` to all first, second, etc. elements of the list `tuples` of `m` tuples, all having the same size `n`, and returns the result as a tuple of size `n`.

*Parameters:*
* `fn` - the function object that accepts every sequence of `i`-th elements of tuples, 
* `tuples` - the list of one or more tuples of the same size.

*Return value:*
value of type `std::tuple<Ts...>` with each type in the pack `Ts...` being given by the return type of `fn`, constructed by applying `fn` to `std::get<i>(std::forward<Tuples>(tuples))...)` for all `i = 0, ..., n - 1`.

