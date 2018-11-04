#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

TEST(all_of_pairs_test, less_than_two)
{
	std::vector<int> v{1};
	
	EXPECT_TRUE(es_util::all_of_pairs(v.begin(), v.begin(), 
		[](...) { return false; }));
	EXPECT_TRUE(es_util::all_of_pairs(v.begin(), v.end(), 
		[](...) { return false; }));	
}

TEST(all_of_pairs_test, main)
{
	std::vector<int> v{1, 2, 3, 4, 5};	

	EXPECT_TRUE(es_util::all_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 2; }));
	EXPECT_FALSE(es_util::all_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 3; }));
}

TEST(any_of_pairs_test, less_than_two)
{
	std::vector<int> v{1};

	EXPECT_FALSE(es_util::any_of_pairs(v.begin(), v.begin(), 
		[](...) { return true; }));
	EXPECT_FALSE(es_util::any_of_pairs(v.begin(), v.end(), 
		[](...) { return true; }));
}

TEST(any_of_pairs_test, main)
{
	std::vector<int> v{1, 2, 3, 4, 5};	

	EXPECT_TRUE(es_util::any_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 8; }));
	EXPECT_FALSE(es_util::any_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 9; }));
}

TEST(none_of_pairs_test, less_than_two)
{
	std::vector<int> v{1};
	
	EXPECT_TRUE(es_util::none_of_pairs(v.begin(), v.begin(), 
		[](...) { return false; }));
	EXPECT_TRUE(es_util::none_of_pairs(v.begin(), v.end(), 
		[](...) { return false; }));
}

TEST(none_of_pairs_test, main)
{
	std::vector<int> v{1, 2, 3, 4, 5};	

	EXPECT_TRUE(es_util::none_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 9; }));
	EXPECT_FALSE(es_util::none_of_pairs(v.begin(), v.end(), 
		[](int x, int y) { return x + y > 8; }));
}
