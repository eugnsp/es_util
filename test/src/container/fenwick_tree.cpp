#include <esu/container/fenwick_tree.hpp>

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <numeric>
#include <vector>

inline constexpr std::size_t max_size = 128;

std::size_t seq()
{
	return std::rand() % max_size;
}

std::size_t seq2()
{
	return std::rand() % 8;
}

// Returns the sum of vector elements in the closed range [first, last]
template<typename T>
T sum(const std::vector<T>& v, std::size_t first, std::size_t last)
{
	assert(first <= last && last < v.size());
	return std::accumulate(v.begin() + first, v.begin() + last + 1, T{});
}

template<typename T>
std::size_t lower_bound(const std::vector<T>& v, T value)
{
	return static_cast<std::size_t>(std::lower_bound(v.begin(), v.end(), value) - v.begin());
}

template<typename T>
std::size_t upper_bound(const std::vector<T>& v, T value)
{
	return static_cast<std::size_t>(std::upper_bound(v.begin(), v.end(), value) - v.begin());
}

//////////////////////////////////////////////////////////////////////

void sum_zero()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		const esu::Fenwick_tree<std::size_t> ft(size);
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
		{
			assert(ft[i] == 0);
			assert(ft.sum(i) == 0);

			for (std::size_t j = i; j < size; ++j)
				assert(ft.sum(i, j) == 0);
		}
		assert(ft.sum() == 0);
	}
}

void sum()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size);
		std::generate(v.begin(), v.end(), seq);

		const esu::Fenwick_tree ft(v.begin(), v.end());
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
		{
			assert(ft[i] == v[i]);
			assert(ft.sum(i) == sum(v, 0, i));

			for (std::size_t j = i; j < size; ++j)
				assert(ft.sum(i, j) == sum(v, i, j));
		}
		assert(ft.sum() == sum(v, 0, size - 1));
	}
}

void add()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size);
		std::generate(v.begin(), v.end(), seq);

		esu::Fenwick_tree ft(v.begin(), v.end());
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
		{
			const auto k = seq();
			ft.add(i, k);
			v[i] += k;
		}

		for (std::size_t i = 0; i < size; ++i)
			assert(ft[i] == v[i]);
	}
}

void set()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size);
		std::generate(v.begin(), v.end(), seq);

		esu::Fenwick_tree ft(v.begin(), v.end());
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
		{
			const auto k = seq();
			ft.set(i, k);
			v[i] = k;
		}

		for (std::size_t i = 0; i < size; ++i)
			assert(ft[i] == v[i]);
	}
}

void push()
{
	std::vector<std::size_t> v;
	esu::Fenwick_tree<std::size_t> ft;

	for (std::size_t size = 1; size <= max_size; ++size)
	{
		const auto k = seq();

		v.push_back(k);
		ft.push(k);
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
			assert(ft[i] == v[i]);
	}
}

void pop()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size);
		std::generate(v.begin(), v.end(), seq);

		esu::Fenwick_tree ft(v.begin(), v.end());
		assert(ft.size() == size);

		for (std::size_t i = 0; i < size; ++i)
		{
			const auto k = ft.pop();
			assert(k == v.back());
			v.pop_back();
		}
	}
}

void lower_upper_bounds_zeros()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size, 0);

		std::vector<std::size_t> v_acc(size);
		std::partial_sum(v.begin(), v.end(), v_acc.begin());

		const esu::Fenwick_tree ft(v.begin(), v.end());

		for (std::size_t value : {0, 1})
		{
			assert(ft.lower_bound(value) == lower_bound(v_acc, value));
			assert(ft.upper_bound(value) == upper_bound(v_acc, value));
		}
	}
}

void lower_upper_bounds()
{
	for (std::size_t size = 1; size <= max_size; ++size)
	{
		std::vector<std::size_t> v(size);
		std::generate(v.begin(), v.end(), seq2);

		std::vector<std::size_t> v_acc(size);
		std::partial_sum(v.begin(), v.end(), v_acc.begin());

		const esu::Fenwick_tree ft(v.begin(), v.end());

		const auto max_value = v_acc.back() + 5;
		for (std::size_t value = 0; value <= max_value; ++value)
		{
			assert(ft.lower_bound(value) == lower_bound(v_acc, value));
			assert(ft.upper_bound(value) == upper_bound(v_acc, value));
		}
	}
}

#define TEST(fn)                                                                                   \
	do                                                                                             \
	{                                                                                              \
		std::cout << #fn ": ";                                                                     \
		fn();                                                                                      \
		std::cout << "OK" << std::endl;                                                            \
	} while (false)

int main()
{
	std::srand(0);

	TEST(sum_zero);
	TEST(sum);

	TEST(add);
	TEST(set);

	TEST(push);
	TEST(pop);

	TEST(lower_upper_bounds_zeros);
	TEST(lower_upper_bounds);

	std::cout << "All OK" << std::endl;
	return 0;
}
