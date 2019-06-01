# Fenwick tree (binary indexed tree)

Header: `<es_util/container/fenwick_tree.hpp>`\
Namespace: `es_util`

---

```cpp
template<typename Value_, typename Size_ = std::size_t>
class Fenwick_tree;
```

*Template parameters:*
* `Value_` - the type of elements,
* `Size_` - the signed integer type used to identify elements in the container.

---

## Member types

```cpp
using Value = Value_;
using Size = Size_;
```
---

## Member functions

### `Fenwick_tree`
**Constructors**

```cpp
Fenwick_tree();
```

Default constructor. Constructs the empty Fenwick tree.

```cpp
Fenwick_tree(Size size);
```

Constructs the Fenwick tree of the size `size` with value initialized elements (`Value()`).

*Time complexity:* linear, `O(size)`.

*Parameters:*
* `size` - the size of the container.

```cpp
Fenwick_tree(std::vector<Value> data);
```

Constructs the Fenwick tree with the contents of the vector `data`, moving its contents into the container.

*Parameters:*
* `data` - the vector to move the contents from.

*Time complexity:* linear, `O(data.size())`.

```cpp
template<class Input_iterator1, class Input_iterator2>
Fenwick_tree(Input_iterator1 first, Input_iterator2 last);
```

Constructs the Fenwick tree with the contents of the range `[first, last)`.

*Parameters:*
* `first`, `last` - the range to copy the elements from.

*Time complexity:* linear, `O(last - first)`.

```cpp
Fenwick_tree(std::initializer_list<Value> list);
```

Constructs the Fenwick tree with the contents of the initializer list `list`.

*Parameters:*
* `list` - initializer list to initialize the elements of the container with.

*Time complexity:* linear, `O(list.size())`.

### `is_empty`, `size`, `capacity`

```cpp
bool is_empty() const;
```

Checks if the container has no elements.

*Return value:*
`true` if the container is empty, and `false` otherwise.

*Time complexity:* constant.

```cpp
Size size() const;
```

Returns the number of elements in the container.

*Time complexity:* constant.

```cpp
Size capacity() const;
```

Returns the number of elements that the container has currently allocated space for.

*Time complexity:* constant.

### `operator[]`
**Retrieves the given element**

```cpp
Value operator[](Size index) const;
```

Returns the element with the index `index`.

*Parameters:*
* `index` - index of the element to return.

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

### `get`
**Retrieves all elements**

```cpp
template<class Random_access_iterator>
void get(Random_access_iterator dest);
```

Stores all elements in the range `[dest, dest + size)`, where `size` is the size of the container.

*Parameters:*
* `dest` - the beginning of the destination range, should be a random access iterator.

*Time complexity:* linear in the size of the container, `O(size())`.

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

1. Returns the sum of elements in the closed range `[first, last]`.
2. Returns the prefix sum, i.e. the sum of elements in the closed range `[0, index]`.
3. Returns the sum of all element in the container. *Precondition:* the container should be non-empty.

*Parameters:*
* `first`, `last` - the range of elements to calculate the sum of.
* `index` - index of the last element in the range to calculate the sum of.

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

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

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

### `reset`
**Replaces the contents of the container**

```cpp
// 1.
void reset(Size size);
// 2.
void reset(std::vector<Value> data);
// 3.
void reset(Input_iterator1 first, Input_iterator2 last);
```

1. Replaces the contents with `size` copies of the zero value (`= Value{}`).
2. Replaces the contents with the contents of `data`.
3. Replaces the contents with copies of values in the range `[first, last)`.

*Parameters:*
* `size` - the new size of the container,
* `data` - the vector to move the contents from,
* `first`, `last` - the range to copy the elements from.

*Time complexity:* linear in the new size of the container, 1. `O(size)`, 2. `O(data.size())`, 3. `O(last - first)`.

### `add`
**Increments the given element**

```cpp
void add(Size index, const Value& value);
```

Adds the value `value` to the element with the index `index`.

*Parameters:*
* `index` - index of the element to add to,
* `value` - value to add.

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

### `set`
**Sets the given element**

```cpp
void set(Size index, const Value& value);
```

Sets the value of the element with the index `index` to `value`.

*Parameters:*
* `index` - index of the element to add to,
* `value` - value to set.

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

### `push`
**Adds an element to the end*

```cpp
void push(const Value& value);
```

Appends the given element value to the end of the container.

*Parameters:*
* `value` - value to append.

*Time complexity:* logarithmic in the size of the container, `O(log(size()))`.

### `pop`
**Removes the last element*

```cpp
void pop();
```

Removes the last element of the container.

*Time complexity:* constant.
