#pragma once
#include <es_util/array.hpp>

#include <cassert>
#include <iostream>

void to_array_main()
{
	constexpr int c_arr1[] = {1, 2, 3};
	constexpr auto arr1 = es_util::to_array(c_arr1);

	static_assert(arr1.size() == 3);
	static_assert(arr1[0] == 1);
	static_assert(arr1[1] == 2);
	static_assert(arr1[2] == 3);

	constexpr int c_arr2[] = {2, 3, 4};
	constexpr auto arr2 = es_util::to_array(c_arr2);

	static_assert(arr2.size() == 3);
	static_assert(arr2[0] == 2);
	static_assert(arr2[1] == 3);
	static_assert(arr2[2] == 4);
}

int main()
{
	to_array_main();

	std::cout << "OK.\n";
	return 0;
}
