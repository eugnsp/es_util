#include <es_util/array.hpp>

#include <array>
#include <cassert>
#include <iostream>
#include <type_traits>

void array_sum_main()
{
	constexpr std::array<int, 5> arr{1, 2, 3, 4, 5};

	constexpr auto sum1 = es_util::array_sum(arr, 5);
	constexpr auto sum2 = es_util::array_sum(arr, 5L);

	static_assert(sum1 == 20);
	static_assert(sum2 == 20);

	static_assert(std::is_same_v<std::remove_const_t<decltype(sum1)>, int>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(sum2)>, long>);
}

void array_sum_n_main()
{
	constexpr std::array<int, 5> arr{1, 2, 3, 4, 5};

	constexpr auto sum1 = es_util::array_sum_n<4>(arr, 5);
	constexpr auto sum2 = es_util::array_sum_n<4>(arr, 5L);

	static_assert(sum1 == 15);
	static_assert(sum2 == 15);

	static_assert(std::is_same_v<std::remove_const_t<decltype(sum1)>, int>);
	static_assert(std::is_same_v<std::remove_const_t<decltype(sum2)>, long>);
}

int main()
{
	array_sum_main();
	array_sum_n_main();

	std::cout << "OK.\n";
	return 0;
}
