#include <gtest/gtest.h>

#include "algorithm/all_any_none_of_pairs_test.hpp"
#include "algorithm/find_test.hpp"
#include "algorithm/for_each_pair_test.hpp"
#include "algorithm/sort_test.hpp"

GTEST_API_ int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}