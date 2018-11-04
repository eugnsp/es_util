#pragma once
#include <es_util/type_traits.hpp>

TEST(type_traits_index_of, main)
{
	EXPECT_EQ((es_util::index_of<int /*, empty list */>), 0);

	EXPECT_EQ((es_util::index_of<int, int>), 0);
	EXPECT_EQ((es_util::index_of<long, int>), 1);

	EXPECT_EQ((es_util::index_of<int, int, void, double>), 0);
	EXPECT_EQ((es_util::index_of<void, int, void, double>), 1);
	EXPECT_EQ((es_util::index_of<double, int, void, double>), 2);
	EXPECT_EQ((es_util::index_of<float, int, void, double>), 3);
}
