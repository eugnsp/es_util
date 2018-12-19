#pragma once
#include <es_util/bitwise.hpp>

#include <cassert>
#include <climits>
#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <vector>

namespace es_util
{
template<typename T>
class Fenwick_tree
{
public:
	Fenwick_tree(std::size_t size) :
		data_(size)
	{
		assert(data_.size() > 0);
	}

	template<class Input_iterator1, class Input_iterator2>
	Fenwick_tree(Input_iterator1 first, Input_iterator2 last) :
		data_{first, last}
	{
		assert(data_.size() > 0);

		for (std::size_t index = 0; index < size(); ++index)
			if (const auto p = parent(index); p < size())
				data_[p] += data_[index];
	}

	Fenwick_tree(std::initializer_list<T> list) :
		Fenwick_tree(list.begin(), list.end())
	{}

	std::size_t size() const
	{
		return data_.size();
	}

	//////////////////////////////////////////////////////////////////////
	/** Element access */

	// Returns the element with the given index
	T operator[](std::size_t index) const
	{
		assert(index < size());

		auto value = data_[index];
		for (std::size_t mask = 1; (index & mask) != 0; mask <<= 1)
			value -= data_[index ^ mask];

		return value;
	}

	// Returns the sum of elements in the given closed range [first, last]
	T sum(std::size_t first, std::size_t last) const
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
	T sum(std::size_t index) const
	{
		return sum(0, index);
	}

	T sum() const
	{
		return sum(size() - 1);
	}

	// Returns the smallest index such that the prefix sum is not less than the given value,
	// or the container's size if no such index exists; all elements in the container should be
	// non-negative, so that the sequence of all prefix sums is non-decreasing
	std::size_t lower_bound(T value) const
	{
		std::size_t index = 0;
		for (auto mask = msb_size_mask(); mask != 0; mask >>= 1)
			if (const auto k = mask + index - 1; k < size() && data_[k] < value)
			{
				value -= data_[k];
				index += mask;
			}

		return index;
	}

	// Returns the smallest index such that the prefix sum is greater than the given value,
	// or the container's size if no such index exists; all elements in the container should be
	// non-negative, so that the sequence of all prefix sums is non-decreasing
	std::size_t upper_bound(T value) const
	{
		std::size_t index = 0;
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
	void add(std::size_t index, const T& value)
	{
		assert(index < size());
		for (; index < size(); index = parent(index))
			data_[index] += value;
	}

	// Sets the value of the element with the given index
	void set(std::size_t index, const T& value)
	{
		add(index, value - (*this)[index]);
	}

private:
	// Returns the minimum size of the Fenwick tree such that the underlying binary tree
	// is perfect, i.e. returns (2^k) if the Fenwick tree size is in the range (2^{k-1}, 2^k]
	std::size_t msb_size_mask() const
	{
		const auto offset = CHAR_BIT * sizeof(std::size_t) - n_leading_zero_bits(size() - 1);
		return static_cast<std::size_t>(1) << offset;
	}

	// Returns the index of the deepest left-most child
	static constexpr std::size_t child(std::size_t index)
	{
		return index & (index + 1);
	}

	// Returns the index of the parent node that is stored in the tree
	static constexpr std::size_t parent(std::size_t index)
	{
		return index | (index + 1);
	}

private:
	std::vector<T> data_;
};

template<class Input_iterator1, class Input_iterator2>
Fenwick_tree(Input_iterator1, Input_iterator2) ->
	Fenwick_tree<typename std::iterator_traits<Input_iterator1>::value_type>;
}
