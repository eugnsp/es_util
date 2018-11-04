#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

TEST(algorithm_for_each_pair_test, empty)
{
	std::vector<int> v{};
	
	int n = 0;
	es_util::for_each_pair(v.begin(), v.end(), [&n](...) { ++n; });
	
	EXPECT_EQ(n, 0);
}

TEST(algorithm_for_each_pair_test, one)
{
	std::vector<int> v{1};
	
	int n = 0;
	es_util::for_each_pair(v.begin(), v.end(), [&n](...) { ++n; });
	
	EXPECT_EQ(n, 0);
}

TEST(algorithm_for_each_pair_test, two)
{
	std::vector<int> v{1, 2};
	std::vector<std::pair<int, int>> o;
	
	es_util::for_each_pair(v.begin(), v.end(), [&o](int x, int y) { o.push_back({x, y}); });
	
	ASSERT_EQ(o.size(), 1);
	EXPECT_EQ(o.front(), std::make_pair(1, 2));
}

TEST(algorithm_for_each_pair_test, main)
{
	std::vector<int> v{1, 2, 3, 4, 5};	
	std::vector<std::pair<int, int>> o;

	es_util::for_each_pair(v.begin(), v.end(), [&o](int x, int y) { o.push_back({x, y}); });
	
	ASSERT_EQ(o.size(), 4);
	EXPECT_EQ(o[0], std::make_pair(1, 2));
	EXPECT_EQ(o[1], std::make_pair(2, 3));
	EXPECT_EQ(o[2], std::make_pair(3, 4));
	EXPECT_EQ(o[3], std::make_pair(4, 5));
}

TEST(algorithm_for_each_pair_n_test, negative_zero)
{
	std::vector<int> v{1, 2, 3, 4, 5};	
	
	int n = 0;
	es_util::for_each_pair_n(v.begin(), -1, [&n](...) { ++n; });
	
	EXPECT_EQ(n, 0);
}

TEST(algorithm_for_each_pair_n_test, zero)
{
	std::vector<int> v{1, 2, 3, 4, 5};	
	
	int n = 0;
	es_util::for_each_pair_n(v.begin(), 0, [&n](...) { ++n; });
	
	EXPECT_EQ(n, 0);
}

TEST(algorithm_for_each_pair_n_test, main)
{
	std::vector<int> v{1, 2, 3, 4, 5};	
	std::vector<std::pair<int, int>> o;

	es_util::for_each_pair_n(v.begin(), 4, [&o](int x, int y) { o.push_back({x, y}); });
	
	ASSERT_EQ(o.size(), 4);
	EXPECT_EQ(o[0], std::make_pair(1, 2));
	EXPECT_EQ(o[1], std::make_pair(2, 3));
	EXPECT_EQ(o[2], std::make_pair(3, 4));
	EXPECT_EQ(o[3], std::make_pair(4, 5));
	
	o.clear();
	es_util::for_each_pair_n(v.begin() + 1, 3, [&o](int x, int y) { o.push_back({x, y}); });
	
	ASSERT_EQ(o.size(), 3);
	EXPECT_EQ(o[0], std::make_pair(2, 3));
	EXPECT_EQ(o[1], std::make_pair(3, 4));
	EXPECT_EQ(o[2], std::make_pair(4, 5));
}
