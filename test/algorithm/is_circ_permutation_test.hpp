#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

TEST(algorithm_circ_permutation_test, empty)
{
	std::vector<int> v1;
	std::vector<int> v2;

	const auto p = es_util::is_circ_permutation(v1.begin(), v1.end(), v2.begin());
	EXPECT_TRUE(p);
}

TEST(algorithm_circ_permutation_test, is_circ_permutation)
{
	std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
	std::vector<int> v2{3, 4, 5, 6, 7, 1, 2};
	std::vector<int> v3{5, 6, 7, 1, 2, 3, 4};

	EXPECT_TRUE(es_util::is_circ_permutation(v1.begin(), v1.end(), v2.begin()));
	EXPECT_TRUE(es_util::is_circ_permutation(v1.begin(), v1.end(), v3.begin()));
}

TEST(algorithm_circ_permutation_test, is_not_circ_permutation)
{
	std::vector<int> v1{1, 2, 3, 4, 5, 6, 7};
	std::vector<int> v2{4, 3, 5, 6, 7, 1, 2};
	std::vector<int> v3{6, 5, 7, 1, 2, 3, 4};
	std::vector<int> v4{9, 5, 7, 1, 2, 3, 4};

	EXPECT_FALSE(es_util::is_circ_permutation(v1.begin(), v1.end(), v2.begin()));
	EXPECT_FALSE(es_util::is_circ_permutation(v1.begin(), v1.end(), v3.begin()));
	EXPECT_FALSE(es_util::is_circ_permutation(v1.begin(), v1.end(), v4.begin()));
}
