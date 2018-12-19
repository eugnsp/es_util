# Fenwick tree (binary indexed tree)

Header: `<es_util/container/fenwick_tree.hpp>`

---

```cpp
template<typename Value_, typename Size_ = std::size_t>
class Fenwick_tree;
```

*Template parameters:*
* `Value_` - the type of elements,
* `Size_` - the signed integer type used to identify elements in the container.

---

## Member types:

```cpp
using Value = Value_;
using Size = Size_;
```
---

## Member functions:

### `Fenwick_tree`
**Constructors**

```cpp
Fenwick_tree();
```

Default constructor. Constructs the empty Fenwick tree.

```cpp
Fenwick_tree(Size size);
```

Constructs the Fenwick tree of the size `size` initialized with the zero value (`Value{}`).

*Parameters:*
* `size` - the size of the container.

```cpp
template<class Input_iterator1, class Input_iterator2>
Fenwick_tree(Input_iterator1 first, Input_iterator2 last);
```

Constructs the Fenwick tree with the contents of the range `[first, last)`.

*Parameters:*
* `first`, `last` - the range to copy the elements from.

```cpp
Fenwick_tree(std::initializer_list<Value> list);
```

Constructs the Fenwick tree with the contents of the initializer list `list`.

*Parameters:*
* `list` - initializer list to initialize the elements of the container with.

### `size`, `is_empty`

```cpp
Size size() const;
```

Returns the number of elements in the container.

```cpp
bool is_empty() const;
```

Checks if the container has no elements.

*Return value:*
`true` if the container is empty, and `false` otherwise.

### `operator[]`
**Accesses the given element**

```cpp
Value operator[](Size index) const;
```

Returns the element with the index `index`.

*Parameters:*
* `index` - index of the element to return.

### `sum`
**Range sum calculation**

```cpp
// 1.
Value sum(Size first, Size last) const;
// 2.
Value sum(Size index) const;
// 3.
Value sum() const;
```

1. Returns the sum of elements in the closed range `[first, last)`.
2. Returns the prefix sum for the element with the index `index`, i.e. the sum of elements in the closed range `[0, index]`.
3. Returns the sum of all element in the container. *Precondition:* the container should be non-empty.

*Parameters:*
* `first`, `last` - the range of elements to calculate the sum of.
* `index` - index of the last element in the range to calculate the sum of.

### `lower_bound`, `upper_bound`
**Lower/upper bound binary search in a Fenwick tree with non-decreasing prefix sums**

```cpp
// 1.
Size lower_bound(Value value) const;
// 2.
Size upper_bound(Value value) const;
```

1. Returns the smallest index such that the prefix sum is not less than the value `value`, or the container's size if no such index exists.
2. Returns the smallest index such that the prefix sum is greater than the value `value`, or the container's size if no such index exists.

*Precondition:* the container should be non-empty and all elements should be non-negative, so that the sequence of all prefix sums is non-decreasing (sorted).

### `reset`
**Replaces the contents of the container**

```cpp
// 1.
void reset(Size size);
// 2.
void reset(Input_iterator1 first, Input_iterator2 last);
```

1. Replaces the contents with `size` copies of the zero value (`= Value{}`).
2. Replaces the contents with copies of values in the range `[first, last)`.

*Parameters:*
* `size` - the new size of the container,
* `first`, `last` - the range to copy the elements from.

### `add`
**Increments the given element**

```cpp
void add(Size index, const Value& value);
```

Adds the value `value` to the element with the index `index`.

*Parameters:*
* `index` - index of the element to add to,
* `value` - value to add.

### `set`
**Sets the given element**

```cpp
void set(Size index, const Value& value);
```

Sets the value of the element with the index `index` to `value`.

*Parameters:*
* `index` - index of the element to add to,
* `value` - value to set.
