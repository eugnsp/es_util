#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

class All_any_none_of_pairs_test : public testing::Test
{
protected:
	std::vector<int> in0{};
	std::vector<int> in1{1};
	std::vector<int> in5{1, 2, 3, 4, 5};	
};

class All_of_pairs_test : public All_any_none_of_pairs_test { };
class Any_of_pairs_test : public All_any_none_of_pairs_test { };
class None_of_pairs_test : public All_any_none_of_pairs_test { };

TEST_F(All_of_pairs_test, less_than_two_test)
{
	EXPECT_TRUE(es_util::all_of_pairs(in0.begin(), in0.end(), 
		[](int, int) { return false; }));
	EXPECT_TRUE(es_util::all_of_pairs(in1.begin(), in1.end(), 
		[](int, int) { return false; }));	
}

TEST_F(All_of_pairs_test, main_test)
{
	EXPECT_TRUE(es_util::all_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 2; }));
	EXPECT_FALSE(es_util::all_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 3; }));
}

TEST_F(Any_of_pairs_test, less_than_two_test)
{
	EXPECT_FALSE(es_util::any_of_pairs(in0.begin(), in0.end(), 
		[](int, int) { return true; }));
	EXPECT_FALSE(es_util::any_of_pairs(in1.begin(), in1.end(), 
		[](int, int) { return true; }));
}

TEST_F(Any_of_pairs_test, main_test)
{
	EXPECT_TRUE(es_util::any_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 8; }));
	EXPECT_FALSE(es_util::any_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 9; }));
}

TEST_F(None_of_pairs_test, less_than_two_test)
{
	std::vector<int> in0{};	
	std::vector<int> in1{1};	
	
	EXPECT_TRUE(es_util::none_of_pairs(in0.begin(), in0.end(), 
		[](int, int) { return false; }));
	EXPECT_TRUE(es_util::none_of_pairs(in1.begin(), in1.end(), 
		[](int, int) { return false; }));
}

TEST_F(None_of_pairs_test, main_test)
{
	EXPECT_TRUE(es_util::none_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 9; }));
	EXPECT_FALSE(es_util::none_of_pairs(in5.begin(), in5.end(), 
		[](int x, int y) { return x + y > 8; }));
}
