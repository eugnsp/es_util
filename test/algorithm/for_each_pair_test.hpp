#pragma once
#include <es_util/algorithm.hpp>
#include <vector>

class For_each_pair_test : public testing::Test
{
protected:
	std::vector<int> in0{};
	std::vector<int> in1{1};
	std::vector<int> in2{1, 2};
	std::vector<int> in5{1, 2, 3, 4, 5};	
	std::vector<int> out;
};

class For_each_pair_n_test : public For_each_pair_test { };

TEST_F(For_each_pair_test, empty_test)
{
	es_util::for_each_pair(in0.begin(), in0.end(),
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	EXPECT_TRUE(out.empty());
}

TEST_F(For_each_pair_test, one_test)
{
	es_util::for_each_pair(in1.begin(), in1.end(),
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	EXPECT_TRUE(out.empty());
}

TEST_F(For_each_pair_test, two_test)
{
	es_util::for_each_pair(in2.begin(), in2.end(),
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	ASSERT_EQ(out.size(), 2);
	EXPECT_EQ(out[0], 1); EXPECT_EQ(out[1], 2);
}

TEST_F(For_each_pair_test, main_test)
{
	es_util::for_each_pair(in5.begin(), in5.end(),
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	ASSERT_EQ(out.size(), 8);
	EXPECT_EQ(out[0], 1); EXPECT_EQ(out[1], 2);
	EXPECT_EQ(out[2], 2); EXPECT_EQ(out[3], 3);
	EXPECT_EQ(out[4], 3); EXPECT_EQ(out[5], 4);
	EXPECT_EQ(out[6], 4); EXPECT_EQ(out[7], 5);
}

TEST_F(For_each_pair_n_test, negative_test)
{
	es_util::for_each_pair_n(in5.begin(), -1,
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	EXPECT_TRUE(out.empty());
}

TEST_F(For_each_pair_n_test, zero_test)
{
	es_util::for_each_pair_n(in0.begin(), 0,
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	EXPECT_TRUE(out.empty());
}

TEST_F(For_each_pair_n_test, main_test)
{
	es_util::for_each_pair_n(in5.begin(), 4,
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	ASSERT_EQ(out.size(), 8);
	EXPECT_EQ(out[0], 1); EXPECT_EQ(out[1], 2);
	EXPECT_EQ(out[2], 2); EXPECT_EQ(out[3], 3);
	EXPECT_EQ(out[4], 3); EXPECT_EQ(out[5], 4);
	EXPECT_EQ(out[6], 4); EXPECT_EQ(out[7], 5);
	
	out.clear();
	es_util::for_each_pair_n(in5.begin() + 1, 3,
		[this](int x, int y) { out.push_back(x); out.push_back(y); });
	
	ASSERT_EQ(out.size(), 6);
	EXPECT_EQ(out[0], 2); EXPECT_EQ(out[1], 3);
	EXPECT_EQ(out[2], 3); EXPECT_EQ(out[3], 4);
	EXPECT_EQ(out[4], 4); EXPECT_EQ(out[5], 5);
}
