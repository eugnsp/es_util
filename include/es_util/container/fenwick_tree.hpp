#pragma once
#include <es_util/bitwise.hpp>

#include <cassert>
#include <climits>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <type_traits>
#include <vector>

namespace es_util
{
template<typename Value_, typename Size_ = std::size_t>
class Fenwick_tree
{
public:
	using Value = Value_;
	using Size = Size_;

public:
	// Constructs an empty Fenwick tree
	Fenwick_tree() = default;

	// Constructs a Fenwick tree of the given size initialized with zero values
	Fenwick_tree(Size size) : data_(size)
	{
		assert(!data_.empty());
	}

	// Constructs a Fenwick tree with the contents of the given range [first, last)
	template<class Input_iterator1, class Input_iterator2>
	Fenwick_tree(Input_iterator1 first, Input_iterator2 last) : data_{first, last}
	{
		assert(!data_.empty());
		construct_in_place();
	}

	// Constructs a Fenwick tree with the contents of the given initializer list
	Fenwick_tree(std::initializer_list<Value> list) : Fenwick_tree(list.begin(), list.end())
	{}

	// Replaces the contents with the given number of zero values
	void reset(Size size)
	{
		assert(size > 0);
		data_.assign(size, Value{});
	}

	// Replaces the contents with copies of values in the given range [first, last)
	template<class Input_iterator1, class Input_iterator2>
	void reset(Input_iterator1 first, Input_iterator2 last)
	{
		assert(first != last);
		data_.assign(first, last);
		construct_in_place();
	}

	Size size() const
	{
		return static_cast<Size>(data_.size());
	}

	bool is_empty() const
	{
		return data_.empty();
	}

	//////////////////////////////////////////////////////////////////////
	/** Element access */

	// Returns the element with the given index
	Value operator[](Size index) const
	{
		assert(index < size());

		auto value = data_[index];
		for (Size mask = 1; (index & mask) != 0; mask <<= 1)
			value -= data_[index ^ mask];

		return value;
	}

	// Returns the sum of elements in the given closed range [first, last]
	Value sum(Size first, Size last) const
	{
		assert(first <= last && last < size());

		auto sum = data_[last];

		last = child(last);
		while (last > first)
		{
			sum += data_[--last];
			last = child(last);
		}

		while (first != last)
		{
			sum -= data_[--first];
			first = child(first);
		}

		return sum;
	}

	// Returns the prefix sum for the element with the given index,
	// i.e. the sum of elements in the closed range [0, index]
	Value sum(Size index) const
	{
		return sum(0, index);
	}

	// Returns the sum of all elements; the container should be non-empty
	Value sum() const
	{
		assert(!is_empty());
		return sum(size() - 1);
	}

	// Returns the smallest index such that the prefix sum is not less than the given value,
	// or the container's size if no such index exists; the container should be non-empty and all
	// elements should be non-negative, so that the sequence of all prefix sums is non-decreasing
	Size lower_bound(Value value) const
	{
		Size index = 0;
		for (auto mask = msb_size_mask(); mask != 0; mask >>= 1)
			if (const auto k = mask + index - 1; k < size() && data_[k] < value)
			{
				value -= data_[k];
				index += mask;
			}

		return index;
	}

	// Returns the smallest index such that the prefix sum is greater than the given value,
	// or the container's size if no such index exists; the container should be non-empty and all
	// elements should be non-negative, so that the sequence of all prefix sums is non-decreasing
	Size upper_bound(Value value) const
	{
		Size index = 0;
		for (auto mask = msb_size_mask(); mask != 0; mask >>= 1)
			if (const auto k = mask + index - 1; k < size() && !(value < data_[k]))
			{
				value -= data_[k];
				index += mask;
			}

		return index;
	}

	//////////////////////////////////////////////////////////////////////
	/** Modifiers */

	// Adds the given value to the element with the given index
	void add(Size index, const Value& value)
	{
		assert(index < size());
		for (; index < size(); index = parent(index))
			data_[index] += value;
	}

	// Sets the value of the element with the given index
	void set(Size index, const Value& value)
	{
		add(index, value - (*this)[index]);
	}

private:
	// Returns the minimum size of the Fenwick tree such that the underlying binary tree
	// is perfect, i.e. returns (2^k) if the Fenwick tree size is in the range (2^{k-1}, 2^k]
	Size msb_size_mask() const
	{
		const auto offset = CHAR_BIT * sizeof(Size) - n_leading_zero_bits(size() - 1);
		return static_cast<Size>(1) << offset;
	}

	// Returns the index of the deepest left-most child
	static constexpr Size child(Size index)
	{
		return index & (index + 1);
	}

	// Returns the index of the parent node that is stored in the tree
	static constexpr Size parent(Size index)
	{
		return index | (index + 1);
	}

	// Converts (data) array into a Fenwick tree in-place
	void construct_in_place()
	{
		for (Size index = 0; index < size(); ++index)
			if (const auto p = parent(index); p < size())
				data_[p] += data_[index];
	}

private:
	std::vector<Value> data_;
};

template<class Input_iterator1, class Input_iterator2>
Fenwick_tree(Input_iterator1, Input_iterator2) -> Fenwick_tree<
	typename std::iterator_traits<Input_iterator1>::value_type,
	std::make_unsigned_t<typename std::iterator_traits<Input_iterator1>::difference_type>>;
} // namespace es_util
