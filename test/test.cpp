#include <gtest/gtest.h>

#include "algorithm/all_any_none_of_pairs_test.hpp"
#include "algorithm/find_test.hpp"
#include "algorithm/for_each_pair_test.hpp"
#include "algorithm/is_circ_permutation_test.hpp"
#include "algorithm/sort_test.hpp"

#include "array/core_test.hpp"
#include "array/sum_test.hpp"
#include "array/to_array_test.hpp"

#include "string/ends_with_test.hpp"

#include "type_traits/all_any_none_test.hpp"
#include "type_traits/index_of_test.hpp"
#include "type_traits/nth_test.hpp"

GTEST_API_ int main(int argc, char **argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}