#pragma once
#include <esu/type_traits.hpp>

TEST(type_traits_index_of_test, main)
{
	EXPECT_EQ((esu::index_of<int /*, empty list */>), 0);

	EXPECT_EQ((esu::index_of<int, int>), 0);
	EXPECT_EQ((esu::index_of<long, int>), 1);

	EXPECT_EQ((esu::index_of<int, int, void, double>), 0);
	EXPECT_EQ((esu::index_of<void, int, void, double>), 1);
	EXPECT_EQ((esu::index_of<double, int, void, double>), 2);
	EXPECT_EQ((esu::index_of<float, int, void, double>), 3);
}
