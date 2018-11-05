#pragma once
#include <es_util/array.hpp>

#include <array>

TEST(array_sum_test, main)
{
	std::array<int, 5> arr{1, 2, 3, 4, 5};
	
	auto sum1 = es_util::array_sum(arr, 5);
	auto sum2 = es_util::array_sum(arr, 5L);
	
	EXPECT_EQ(sum1, 20);
	EXPECT_EQ(sum2, 20);
	
	testing::StaticAssertTypeEq<decltype(sum1), int>();
	testing::StaticAssertTypeEq<decltype(sum2), long>();
}

TEST(array_sum_n_test, main)
{
	std::array<int, 5> arr{1, 2, 3, 4, 5};
	
	auto sum1 = es_util::array_sum_n<4>(arr, 5);
	auto sum2 = es_util::array_sum_n<4>(arr, 5L);
	
	EXPECT_EQ(sum1, 15);
	EXPECT_EQ(sum2, 15);
	
	testing::StaticAssertTypeEq<decltype(sum1), int>();
	testing::StaticAssertTypeEq<decltype(sum2), long>();
}
