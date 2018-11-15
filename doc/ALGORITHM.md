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
