#pragma once
#include <es_util/array.hpp>

TEST(array_to_array_test, main)
{
	constexpr int c_arr1[] = {1, 2, 3};
	constexpr auto arr1 = es_util::to_array(c_arr1);

	static_assert(arr1.size() == 3);
	static_assert(arr1[0] == 1);
	static_assert(arr1[1] == 2);
	static_assert(arr1[2] == 3);

	constexpr int c_arr2[] = {2, 3, 4};
	constexpr auto arr2 = es_util::to_array(c_arr2);

	ASSERT_EQ(arr2.size(), 3);
	EXPECT_EQ(arr2[0], 2);
	EXPECT_EQ(arr2[1], 3);
	EXPECT_EQ(arr2[2], 4);

	SUCCEED();
}
